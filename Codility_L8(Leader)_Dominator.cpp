#include <vector>
#include <unordered_map>

// Using unordered_map to count occurencies of the elements of A
// Detected time complexity: O(N* log(N)) or O(N)
int solution(std::vector<int>& A)
{
	std::unordered_map<int, size_t> occurencies;
	size_t max = 0;
	int index = -1;

	for (size_t i = 0; i != A.size(); ++i)
	{
		if (++occurencies[A[i]] > max)
		{
			max = occurencies[A[i]];
			index = i;
		}
	}

	if (max > A.size() / 2)
	{
		return index;
	}

	return -1;
}