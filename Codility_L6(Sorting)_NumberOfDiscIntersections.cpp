#include <vector>

// correct but slow O(N*N) solution (75%)
int slowSolution(std::vector<int>& A) noexcept
{
	if (A.size() < 2) return 0;

	std::vector<long> S(A.size());
	std::vector<long> E(A.size());

	for (size_t i = 0; i != A.size(); ++i)
	{
		S[i] = static_cast<long>(i) - A[i];
		E[i] = static_cast<long>(i) + A[i];
	}

	int sum = 0;
	for (size_t i = 0; i != A.size() - 1; ++i)
	{
		for (size_t j = i + 1; j != A.size(); ++j)
		{
			if ((E[j] >= S[i] && E[j] <= E[i]) || (S[j] >= S[i] && S[j] <= E[i]))
			{
				++sum;
			}
			else if (S[j] < S[i] && E[j] > E[i])
			{
				++sum;
			}
		}
		if (sum > 10000000)
		{
			return -1;
		}
	}

	return sum;
}

int solution(std::vector<int>& A) noexcept
{
	const int size = static_cast<int>(A.size());

	std::vector<int> S(size);
	std::vector<int> E(size);

	// O(N)
	for (int i = 0; i != size; ++i)
	{
		if (i < A[i])
		{
			++S.front();
		}
		else
		{
			++S[i - A[i]];
		}

		if (static_cast<long>(i) + A[i] >= size)
		{
			++E.back();
		}
		else
		{
			++E[i + A[i]];
		}
	}

	int sum = 0;
	int active = 0;
	// O(N)
	for (int i = 0; i != size; ++i)
	{
		sum += active * S[i] + (S[i] * (S[i] - 1)) / 2;

		if (sum > 10000000)
		{
			return -1;
		}

		active += S[i] - E[i];
	}

	return sum;
}