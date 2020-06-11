#include <vector>

int solution(std::vector<int>& A) noexcept
{
	size_t goingRight = 0;
	size_t sum = 0;
	for (size_t i = 0; i != A.size(); ++i)
	{
		if (A[i])
		{
			sum += goingRight;
			if (sum > 1000000000) return -1;
		}
		else
		{
			++goingRight;
		}
	}

	return static_cast<int>(sum);
}