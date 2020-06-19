#include <vector>

// Detected time complexity : O(N * log(log(N)))
int solution(std::vector<int>& A) noexcept
{
	int N = A.size();
	if (N < 3) return 0;

	std::vector<int> peaks(N);
	int counter = 0;

	// peaks array - to store the number of peaks from the beginning of the array A
	// O(N)
	peaks.front() = counter;
	for (int i = 1; i != N - 1; ++i)
	{
		if (A[i] > A[i - 1] && A[i] > A[i + 1])
		{
			++counter;
		}
		peaks[i] = counter;
	}
	peaks.back() = counter;

	if (counter == 0) return 0;
	if (counter == 1) return 1;

	// check the possible setups - where i is a divisor of N, and N <= number of peaks
	int result = 1;
	for (int i = 2; i <= counter; ++i)
	{
		if (N % i == 0)
		{
			bool ok = true;
			int slice = N / i;
			int prev = 0;

			for (int inspected = slice - 1; inspected < N; inspected += slice)
			{
				if (peaks[inspected] > prev)
				{
					prev = peaks[inspected];
				}
				else
				{
					ok = false;
					break;
				}
			}

			if (ok)
			{
				result = i;
			}
		}
	}

	return result;
}