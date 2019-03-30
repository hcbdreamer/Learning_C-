#include<iostream>
using namespace std;

int numberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
		{
			count++;
		}
		flag = flag << 1;//每次把1左移一次与n与运算
	}
	return count;
}
int numberOf1_1(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
		
	}
	return count;
}
int main()
{
	int n = 0x7FFFFFFF;
	int count = numberOf1(n);
	int count1 = numberOf1_1(n);
	cout << count << endl;
	cout << count1 << endl;
}