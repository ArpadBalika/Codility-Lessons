#include <stack>
#include <string>

inline bool isOpening(char c)
{
	return c == '(' || c == '[' || c == '{';
}

int solution(std::string& S) noexcept
{
	std::stack<char> openings;

	for (char c : S)
	{
		if (isOpening(c))
		{
			openings.push(c);
		}
		else
		{
			if (openings.empty()) return 0;

			switch (openings.top())
			{
			case '(':
				if (c == ')') openings.pop();
				break;
			case '[':
				if (c == ']') openings.pop();
				break;
			case '{':
				if (c == '}') openings.pop();
				break;
			}
		}
	}

	if (openings.empty()) return 1;

	return 0;
}