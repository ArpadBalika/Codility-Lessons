// could be constexpr
int solution(int X, int Y, int D) noexcept
{
	int dist = Y - X;
	int result = dist / D;
	if (dist % D != 0) return result + 1;
	return result;
}