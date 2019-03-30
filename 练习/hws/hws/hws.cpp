#include <iostream>  
#include<cmath>
using namespace std;

int isHuiwen(int number)
{
	int n = 0;//余数.
	int a;
	int m = number;
	while (m != 0)
	{
		n = n * 10 + m % 10; //number的最低位变为n的最高位 
		m = m / 10;
	}

	if (n == number)
		a = 1;
	else
		a = 0;
	return a;
	
}
int hws(int n)
{
	int min,max,x,y,z,i;
	int c,j;
	min = 1;
	max = pow(10,n) - 1;
	for ( i = max*max; i >=min; i--)
	{
		x = isHuiwen(i);
		if (x == 1)
		{
			for (j = i; j >=1; j--)
			{
				y = i%j;
				z = i / j;
				if (y == 0)
				{
					if (z/10 == j / 10)
					{
						c = i;
						cout << c;
						return c;
						//exit(0);
					}
				}
			}
		}
	}
	
}

int main()
{
	int n=4;
	hws(n);
	return 0;
}