#include <vector>
#include <algorithm>

int solution(std::vector<int>& A) noexcept
{
	if (A.empty()) return 1;
	if (A.size() == 1)
	{
		if (A[0] == 1) return 2;
		return 1;
	}

	std::sort(A.begin(), A.end());

	for (int i = 0; i != static_cast<int>(A.size()); ++i)
	{
		if (A[i] != i + 1) return i + 1;
	}

	return A.size() + 1;
}