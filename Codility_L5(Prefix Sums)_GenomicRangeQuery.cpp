#include <vector>
#include <string>

// Detected time complexity: O(N + M)
// Setting up the "database": count the occurencies for each impact factor at each state.
// Using the "database" we can do each querie in constant time.
std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q)
{
	enum class impact : int
	{
		A = 1,
		C = 2,
		G = 3,
		T = 4
	};

	struct counters
	{
		int A = 0;
		int C = 0;
		int G = 0;
	};

	std::vector<counters> sums(S.size() + 1);
	counters c;

	for (size_t i = 0; i != S.size(); ++i)
	{
		sums[i] = c;
		switch (S[i])
		{
		case 'A':
			++c.A;
			break;
		case 'C':
			++c.C;
			break;
		case 'G':
			++c.G;
			break;
		}
	}
	sums.back() = c;

	std::vector<int> result(P.size());

	for (size_t i = 0; i != P.size(); ++i)
	{
		auto from = P[i];
		auto to = Q[i] + 1;

		if (sums[to].A - sums[from].A > 0)
			result[i] = static_cast<int>(impact::A);
		else if (sums[to].C - sums[from].C > 0)
			result[i] = static_cast<int>(impact::C);
		else if (sums[to].G - sums[from].G > 0)
			result[i] = static_cast<int>(impact::G);
		else
			result[i] = static_cast<int>(impact::T);
	}

	return result;
}