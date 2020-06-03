#include <vector>
#include <algorithm>

// Binary representation of num. (num >= 0)
std::vector<bool> to_binary(int num) noexcept
{
	std::vector<bool> binary;
	while (num)
	{
		binary.push_back(num % 2);
		num >>= 1;
	}
	return binary;
}

// Initial solution.
int solution(int N) noexcept
{
	const auto binary = to_binary(N);
	size_t maxGap = 0;
	auto iter = binary.cbegin();
	const auto iterEnd = binary.cend();

	while (iter != iterEnd)
	{
		auto currentTrue = std::find(iter, iterEnd, true);
		if (currentTrue == iterEnd) break;

		auto nextTrue = std::find(currentTrue + 1, iterEnd, true);
		if (nextTrue == iterEnd) break;

		const auto gap = std::distance(currentTrue, nextTrue) - 1;
		maxGap = std::max(maxGap, static_cast<size_t>(gap));

		iter = nextTrue;
	}

	return maxGap;
}

// Simple solution without helper function, vectors and iterators.
int simpleSolution(int N) noexcept
{
	int maxGap = 0;
	int prev = -1;
	int current = 0;

	while (N)
	{
		bool bit = N % 2;
		N >>= 1;

		if (bit)
		{
			int gap;
			prev == -1 ? gap = 0 : gap = current - prev - 1;
			prev = current;
			maxGap = std::max(maxGap, gap);
		}
		++current;
	}
	return maxGap;
}