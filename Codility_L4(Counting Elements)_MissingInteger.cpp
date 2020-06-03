#include <vector>
#include <algorithm>

int solution(std::vector<int>& A) noexcept
{
	// edge case: only 1 element in the array
	if (A.size() == 1)
		return A.front() != 1 ? 1 : 2;

	std::sort(A.begin(), A.end());

	// edge case: all values in the vector are positive and greater than 1
	// edge case: all values in the vector are negative
	if (A.front() > 1 || A.back() < 1) return 1;

	// iterating through negative integers
	size_t j;
	for (j = 0; j != A.size(); ++j)
	{
		if (A[j] > 0) break;
	}
	if (A[j] != 1) return 1;

	// iterating until we find an outlier element or we reach the end of the array
	for (size_t i = j + 1; i != A.size(); ++i)
	{
		if (A[i - 1] + 1 != A[i] && A[i - 1] != A[i])
			return A[i - 1] + 1;
	}

	// all values in the vector are correct
	return A.back() + 1;
}