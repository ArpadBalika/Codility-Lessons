#include <vector>
#include <algorithm>

int solution(std::vector<int>& A) noexcept
{
	if (A.size() < 2) return 0;

	int max_ending = 0;
	int maxProfit = 0;
	for (size_t i = 1; i != A.size(); ++i)
	{
		max_ending = std::max(0, max_ending + (A[i] - A[i - 1]));
		maxProfit = std::max(maxProfit, max_ending);
	}

	return maxProfit;
}