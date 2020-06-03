#include <vector>

std::vector<int> solution(std::vector<int>& A, int K) noexcept
{
	if (A.empty()) return A;

	const size_t s = A.size();
	std::vector<int> result(s);

	const size_t shift = K > s ? K % s : K;

	for (size_t i = 0; i != s; ++i)
	{
		if (i + shift < s)
			result[i + shift] = A[i];
		else
			result[i + shift - s] = A[i];
	}

	return result;
}