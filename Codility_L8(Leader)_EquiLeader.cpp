#include <vector>
#include <unordered_map>

// Using unordered_map to count occurencies of the elements of A. (solution of the lesson Dominator)
// Detected time complexity: O(N)
int solution(std::vector<int>& A) noexcept
{
	std::unordered_map<int, size_t> occurencies;
	size_t max = 0;
	int number = 0;

	// O(N)
	for (size_t i = 0; i != A.size(); ++i)
	{
		if (++occurencies[A[i]] > max)
		{
			max = occurencies[A[i]];
			number = A[i];
		}
	}

	if (max <= A.size() / 2)
	{
		return 0;
	}

	size_t counter = 0;
	size_t leftSide = 0;

	// O(N)
	for (size_t i = 0; i != A.size() - 1; ++i)
	{
		if (A[i] == number)
		{
			++leftSide;
		}
		if (leftSide > (i + 1) / 2 && max - leftSide > (A.size() - (i + 1)) / 2)
		{
			++counter;
		}
	}

	return counter;
}