#include <vector>
#include <stack>

void bigFishEatsSmallFish(size_t i, std::stack<int>& aliveSize, std::stack<int>& aliveDir, std::vector<int>& A, std::vector<int>& B) noexcept
{
	if (aliveSize.empty() || aliveDir.top() == B[i] || aliveDir.top() == 0)
	{
		aliveSize.push(A[i]);
		aliveDir.push(B[i]);
	}
	else if (aliveSize.top() < A[i])
	{
		aliveSize.pop();
		aliveDir.pop();
		bigFishEatsSmallFish(i, aliveSize, aliveDir, A, B);
	}
}

// Recursive solution. Detected time complexity: O(N)
int solution(std::vector<int>& A, std::vector<int>& B) noexcept
{
	std::stack<int> aliveSize;
	std::stack<int> aliveDir;

	for (size_t i = 0; i != A.size(); ++i)
	{
		bigFishEatsSmallFish(i, aliveSize, aliveDir, A, B);
	}

	return aliveSize.size();
}