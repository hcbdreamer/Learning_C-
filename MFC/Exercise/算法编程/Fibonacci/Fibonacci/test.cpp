#include<iostream>
using namespace std;
long long Fibonacci(unsigned int n);
long long Fibonacci1(unsigned int n);

int main()
{
	int n;
	int m;
	cin >> n;
	m=Fibonacci1(n);
	cout << m;
	return 0;
}
long long Fibonacci(unsigned int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
long long Fibonacci1(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n <2)
	{
		return result[n];
	}
	long long n0 = 0;
	long long n1 = 1;
	long long n2 = 0;
	for (int i = 2; i <= n; i++)
	{
		n2 = n0 + n1;
		n0 = n1;
		n1 = n2;
	}
	return n2;
}