#include <vector>
#include <algorithm>

// First computing the local max slice from two directions of A.
// Then finding the max double slice sum by checking the left and right hand side but not counting the element in the middle.
// O(N)
int solution(std::vector<int>& A) noexcept
{
	std::vector<int> leftSliceLocalMax(A.size());
	std::vector<int> rightSliceLocalMax(A.size());

	for (size_t i = 1; i != A.size() - 1; ++i)
	{
		leftSliceLocalMax[i] = std::max(leftSliceLocalMax[i - 1] + A[i], 0);
	}

	for (size_t i = A.size() - 2; i != 0; --i)
	{
		rightSliceLocalMax[i] = std::max(rightSliceLocalMax[i + 1] + A[i], 0);
	}

	int maxDoubleSliceSum = 0;
	for (size_t i = 1; i != A.size() - 1; ++i)
	{
		maxDoubleSliceSum = std::max(maxDoubleSliceSum, leftSliceLocalMax[i - 1] + rightSliceLocalMax[i + 1]);
	}

	return maxDoubleSliceSum;
}