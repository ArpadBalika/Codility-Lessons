#include <vector>
#include <algorithm>
#include <unordered_set>

// Detected time complexity: O(N* log(N))
// Using stl algorithms: sort and unique, then distance of iters
int solution(std::vector<int>& A) noexcept
{
	// O(N*Log(N))
	std::sort(A.begin(), A.end());
	// O(N)
	auto lastUniqueIt = std::unique(A.begin(), A.end());

	return std::distance(A.begin(), lastUniqueIt);
}

// Using hash table (unordered set)
// Proved to be slower on Codility than the solution above (0.016s vs 0.028s)
int unorderedSetSolution(std::vector<int>& A) noexcept
{
	std::unordered_set<int> us;
	for (const auto& elem : A)
	{
		us.insert(elem);
	}

	return us.size();
}