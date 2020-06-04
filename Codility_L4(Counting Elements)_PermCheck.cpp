#include <vector>
#include <algorithm>

// Naive approach (still 100%): sort, then check if every element is correct
int naiveSolution(std::vector<int>& A) noexcept
{
	std::sort(A.begin(), A.end());

	for (size_t i = 0; i != A.size(); ++i)
	{
		if (A[i] != static_cast<int>(i) + 1) return 0;
	}

	return 1;
}

// O(N) solution using a helper array to check occurencies
int solution(std::vector<int>& A) noexcept
{
	auto Asize = A.size();
	std::vector<bool>occured(Asize + 1);

	for (const auto num : A)
	{
		if (num > static_cast<int>(Asize) || occured[num]) return 0;

		occured[num] = true;
	}

	return 1;
}