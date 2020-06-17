// O(sqrt(N))
int solution(int N) noexcept
{
	long divisor = 1;
	int counter = 0;

	while (divisor * divisor < N)
	{
		if (N % divisor == 0)
		{
			counter += 2;
		}
		++divisor;
	}

	if (divisor * divisor == N)
	{
		++counter;
	}

	return counter;
}