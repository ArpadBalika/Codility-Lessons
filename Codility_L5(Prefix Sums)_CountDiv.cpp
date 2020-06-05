// Finding the first divisible number and the last divisible number in the range is the key to solve this problem in constant time.
int solution(int A, int B, int K) noexcept
{
	if (K == 0) return 0;

	int firstNum = (A / K) * K;
	if (firstNum < A && firstNum + K > B) return 0;

	if (firstNum != A) firstNum += K;

	int lastNum = (B / K) * K;

	return (lastNum - firstNum) / K + 1;
}