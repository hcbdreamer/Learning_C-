#include"test.h"
#include<iostream>
using namespace std;

int main()
{
	replace test;
	//char* str = new char[14]{"we are happy"};
	//char str[14] = { "we are happy." };
	char str[6] = { " we. " };
	test.ReplaceBlank(str,6);
	/*for (int i = 0; i < 18; i++)
	{
		cout <<str[i] << endl;
	}*/
	cout << str << endl;
}