#include <vector>
#include <algorithm>

// Another approach: Use an unordered_map (hash table) to store the number of occurancies,
// then iterate through the hash table elmenets, to find the first element with occurency == 1.

// Another approach with O(N) complexity: Use bitwise XOR operations to find the unique element.

// In this solution I sort the array, then check the elements in pairs whether they are the same.
// Detected time complexity: O(N) or O(N * log(N))
int solution(std::vector<int>& A) noexcept
{
	if (A.size() == 1) return A[0];

	// O(N log(N))
	std::sort(A.begin(), A.end());

	// O(N/2) ~ O(N)
	for (size_t i = 0; i != A.size() - 1; i += 2)
	{
		if (A[i] != A[i + 1])
		{
			return A[i];
		}
	}
	return A.back();
}