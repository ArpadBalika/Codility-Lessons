#include <vector>
#include <algorithm>

int solution(std::vector<int>& A) noexcept
{
	if (A.size() < 3) return 0;

	std::sort(A.begin(), A.end());

	for (size_t i = 0; i != A.size() - 2; ++i)
	{
		if (A[i] > 0)
		{
			if (static_cast<long>(A[i + 1]) + A[i + 2] > A[i] && static_cast<long>(A[i]) + A[i + 2] > A[i + 1] && static_cast<long>(A[i]) + A[i + 1] > A[i + 2])
			{
				return 1;
			}
		}
	}

	return 0;
}