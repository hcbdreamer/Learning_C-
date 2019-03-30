
class sum{
public:
	int GetMaxSum(int A[], int N);
};

int sum::GetMaxSum(int A[], int N)
{
	int ThisSum = 0, MaxSum = 0;
	for (int i = 0; i < N ; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;
		}
	}
	return MaxSum;
}