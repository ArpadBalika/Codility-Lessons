#include <vector>

int solution(int X, std::vector<int>& A) noexcept
{
	std::vector<bool> positionsReady(X + 1);

	for (int i = 0; i != static_cast<int>(A.size()); ++i)
	{
		if (!positionsReady[A[i]])
		{
			--X;
			if (X == 0) return i;

			positionsReady[A[i]] = true;
		}
	}

	return -1;
}