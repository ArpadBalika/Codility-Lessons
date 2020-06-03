#include <vector>

// Approach: update the "applied" max counter and update the values in the result array.
// At the end of the first loop, the result array is in a state where every value is correct if it not smaller than "applied" max.
// There is a second loop to overwrite the smaller than "applied" max elements of the array.
std::vector<int> solution(int N, std::vector<int>& A) noexcept
{
	std::vector<int> result(N);
	int max = 0;
	int appliedMax = 0;

	// O(N)
	for (int i = 0; i != static_cast<int>(A.size()); ++i)
	{
		if (A[i] == N + 1)
		{
			appliedMax = max;
			continue;
		}
		else
		{
			if (result[A[i] - 1] < appliedMax)
				result[A[i] - 1] = appliedMax + 1;
			else
				++result[A[i] - 1];

			if (result[A[i] - 1] > max) max = result[A[i] - 1];
		}
	}

	// O(N)
	for (int i = 0; i != static_cast<int>(result.size()); ++i)
	{
		if (result[i] < appliedMax) result[i] = appliedMax;
	}

	return result;
}