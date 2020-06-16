#include <vector>
#include <algorithm>

int solution(std::vector<int>& A) noexcept
{
	int maxEnding = 0;
	int maxSlice = -1000000;

	for (size_t i = 0; i != A.size(); ++i)
	{
		maxEnding = std::max(std::max(-1000000, maxEnding + A[i]), A[i]);
		maxSlice = std::max(maxSlice, maxEnding);
	}

	return maxSlice;
}