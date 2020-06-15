#include <vector>
#include <stack>

void heightCheck(size_t i, const std::vector<int>& H, std::stack<int>& heights, int& counter) noexcept
{
	if (heights.empty() || heights.top() < H[i])
	{
		heights.push(H[i]);
		++counter;
	}
	else if (heights.top() > H[i])
	{
		heights.pop();
		heightCheck(i, H, heights, counter);
	}
}

// Recursive solution. Detected time complexity: O(N)
int solution(std::vector<int>& H) noexcept
{
	std::stack<int> heights;
	int counter = 0;
	for (size_t i = 0; i != H.size(); ++i)
	{
		heightCheck(i, H, heights, counter);
	}

	return counter;
}