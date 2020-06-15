#include <string>
#include <stack>

int solution(std::string& S) noexcept
{
	std::stack<char> unpaired;

	for (char c : S)
	{
		if (c == '(')
		{
			unpaired.push(c);
		}
		else
		{
			if (unpaired.empty())
			{
				return 0;
			}
			unpaired.pop();
		}
	}

	if (unpaired.empty())
	{
		return 1;
	}
	return 0;
}