#include <vector>
#include <algorithm>

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

		const auto d = std::distance(currentTrue, nextTrue) - 1;
		maxGap = std::max(maxGap, static_cast<size_t>(d));

		iter = nextTrue;
	}

	return maxGap;
}

int main()
{
	unsigned X = 1041;

	auto result = solution(X);

	return 0;
}