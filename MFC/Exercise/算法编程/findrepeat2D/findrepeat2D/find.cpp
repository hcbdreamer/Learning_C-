#include"find.h"
#include<iostream>
using namespace std;

int main(){
	
	//int a[][4]={ { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int b[] = { 1,2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	int** num0 = new int*[4];
    num0[0] = new int[4]{1, 2, 4, 6};
	num0[1] = new int[4]{2, 4, 7, 8};
	num0[2] = new int[4]{8,9, 10, 11};
	num0[3] = new int[4]{9, 12, 13, 15};
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << num0[i][j] << endl;
		}
	}*/


	findrepeat find;
	//if (find.Find(b, 4, 4, 7))
	//if (find.Find(&a[0][0], 4, 4, 7))
	if (find.Find(num0, 4, 4, 7))
	{
		cout << "数组中有该整数!" << endl;
	}
	else
	{
		cout << "数组中没有该整数！" << endl;
	}
}