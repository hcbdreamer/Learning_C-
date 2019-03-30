#include <iostream>
using namespace std;
int Input(long num[], float score[], int array_size);
//参数说明：数组 num 存放学生的学号，数组 score 存放学生的分数, array_size是两个数组的大小。
//返回值：返回班级的实际人数

void Total1(long num[], float score[], int n);
//参数说明：数组 num 存放学生的学号，数组 score 存放学生的分数，n 班级实际人数

void Total2(long num[], float score[], int n);

int main()
{
	long num[60];
	//long* num=new long[];
	//float* score = new float[];
	float score[60];
	int array_size = 37;
	int n = Input(num, score, array_size);
	//cout << n << endl;
	Total1(num, score, n);
	Total2(num, score, n);

	return 0;
}

int Input(long num[], float score[], int array_size)
{

	
	int count = 0;
	for (int i = 0; i < array_size; i++)
	{
		cin >> num[i];
		cin >> score[i];
		count++;
			if (count >30||score[i] < 0)
			{
				cout << "Enter the student number and the score:" << endl;
				return i;
				
			}
	}
	cout << "Enter the student number and the score:" << endl;
	return array_size;
};

void Total1(long num[], float score[], int n)
{

	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (score[i] < 60)
		{
			cout << num[i] << endl;
			total++;
		}
	}
	

	cout << "The score<60 is:" << total << endl;
};
void Total2(long num[], float score[], int n)
{

	int total = 0;
	float sum=0;
	float mean = 0;
	for (int i = 0; i < n; i++)
	{
		sum += score[i];
	}
	mean = sum / n;
	for (int j = 0; j < n; j++)
	{
		if (score[j] >= mean)
		{
			cout << num[j] << endl;
			total++;
		}
	}
	//cout << mean << endl;
	cout << "The score>=average is:" << total << endl;
};
