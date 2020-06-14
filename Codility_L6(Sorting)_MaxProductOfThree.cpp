#include <vector>
#include <algorithm>

int solution(std::vector<int>& A) noexcept
{
	std::sort(A.rbegin(), A.rend());

	auto candidate1 = A[0] * A[1] * A[2];
	auto candidate2 = A[0] * A[A.size() - 2] * A.back();

	if (candidate1 > candidate2)
	{
		return candidate1;
	}

	return candidate2;
}