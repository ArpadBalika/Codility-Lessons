#include <vector>

// simple, slow O(N^2) solution (60%)
int slowSolution(std::vector<int>& A) noexcept
{
	double minAvg = 10000;
	double avg;
	int minAvgIndex = 0;

	for (size_t i = 0; i != A.size() - 1; ++i)
	{
		int sum = A[i];
		for (size_t j = i + 1; j != A.size(); ++j)
		{
			sum += A[j];
			avg = static_cast<double>(sum) / static_cast<double>(j - i + 1);
			if (avg < minAvg)
			{
				minAvg = avg;
				minAvgIndex = static_cast<int>(i);
			}
		}
	}

	return minAvgIndex;
}

// Detected time complexity: O(N)
int solution(std::vector<int>& A) noexcept
{
	std::vector<int> preSum(A.size());

	preSum.front() = A.front();
	// O(N)
	for (size_t i = 1; i != A.size(); ++i)
	{
		preSum[i] = preSum[i - 1] + A[i];
	}

	size_t begin = 0;
	size_t end = 1;
	size_t min_start = begin;
	double minAvg = static_cast<double>(preSum[end] - preSum[begin] + A[begin]) / (end - begin + 1);

	// O(N)
	for (size_t i = 1; i < A.size(); ++i)
	{
		double avg = static_cast<double>(preSum[i] - preSum[begin] + A[begin]) / (i - begin + 1);

		if (avg < minAvg)
		{
			minAvg = avg;
			min_start = begin;
		}

		if (A[i] < minAvg)
			begin = i;
	}

	return static_cast<int>(min_start);
}