#include<iostream>
using namespace std;

int main()
{
	float f1 = 1.1;
	float f2 = 2.1;
	float f3 = f2 - 1;
	cout << f3 << endl;
	if (f1 == f3)
		cout << "f1=f3" << endl;
	else
		cout << "f1!=f3" << endl;
	return 0;
}