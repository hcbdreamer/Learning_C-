#include"test.h"
#include<iostream>
using namespace std;


int main()
{
	/*number number1;
	int num[] = { 1, 3, 1, 0, 2, 5, 3 };
	int repeatnum;
	int length = sizeof(num) / sizeof(num[1]);
	if (number1.repeat(num, length, &repeatnum) == 1){
	cout << "���ظ�����" << endl;
	cout << "����һ���ظ������ǣ�"<<repeatnum << endl;
	}
	else
	{
		cout << "û���ظ�����" << endl;
	}*/
	/*map<int, int>x1;
	cout << x1[2] << endl;*/
	number number1;
	vector<int>repeatnum;
	int num[] = { 1, 3, 1, 0, 2, 5, 3 };
	int length = sizeof(num) / sizeof(num[1]);
	repeatnum=number1.repeat2(num, length);
	cout << "�ظ������ǣ� " << endl;
	for (int i = 0; i < repeatnum.size(); i++)
	{
		cout << repeatnum[i] << endl;
	}
}
