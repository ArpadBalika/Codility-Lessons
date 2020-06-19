int solution(int N) noexcept
{
	long i = 2;
	int max = 1;
	while (i * i <= N)
	{
		if (N % i == 0)
		{
			max = i;
		}
		++i;
	}

	return 2 * (max + (N / max));
}