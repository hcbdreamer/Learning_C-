#include<iostream>
using namespace std;

class binary
{
public:
	void bin_dec(int a);
};

void binary::bin_dec(int a)
{
	int b[16];
	memset(b, 0, sizeof(b));
	int c;
	int i = 0;
	c = a;
	while (c != 0)
	{
		b[15-i] = c % 2;
		c = c / 2;
		i++;
	}
	cout << "The Binary is: ";
	for (int j = 1; j < 17; j++)
	{
		if (j!=0 && j % 4 == 0)
			cout << b[j-1] << " ";
		else
			cout << b[j-1];
	}
}