#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

// Detected time complexity: O(N)
// Approach: store the prefix sums from each direction (2 * (N - 1) steps) then find the min dif in N - 1 steps
int solution(std::vector<int>& A) noexcept
{
	if (A.size() == 2) return abs(A[0] - A[1]);

	std::vector<int> forwardDifs(A.size());
	std::vector<int> backwardDifs(A.size());

	// O(N)
	forwardDifs.front() = A.front();
	for (size_t f = 1; f != A.size() - 1; ++f)
	{
		forwardDifs[f] = A[f] + forwardDifs[f - 1];
	}

	// O(N)
	backwardDifs.back() = A.back();
	for (size_t b = A.size() - 2; b != 0; --b)
	{
		backwardDifs[b] = A[b] + backwardDifs[b + 1];
	}

	// O(N)
	int result = std::numeric_limits<int>::max();
	for (size_t i = 0; i != A.size() - 1; ++i)
	{
		result = std::min(result, abs(forwardDifs[i] - backwardDifs[i + 1]));
	}

	return result;
}