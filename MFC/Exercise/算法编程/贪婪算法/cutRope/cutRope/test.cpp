#include<iostream>
using namespace std;

int findMax(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}
	int timeof3 = length / 3;
	if (length - timeof3*3 == 1)
	{
		timeof3 -= 1;
	}
	int timeof2 = (length - timeof3 * 3) / 2;
	return (int)(pow(3, timeof3))*(int)(pow(2, timeof2));
}

int main()
{
	int max = 0;
	max = findMax(10);
	cout << max << endl;
}