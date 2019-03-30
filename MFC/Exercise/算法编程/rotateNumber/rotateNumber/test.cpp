#include<iostream>
using namespace std;


int FindMin(int* a, int length);
int MinInOrder(int* a, int start, int end);
int main()
{
	//int a[] = { 3, 4, 5, 1, 2 };
	//int a[] = { 1, 2, 3, 4, 5 };
	int a[] = { 1,0, 1, 1, 1};
	int min = FindMin(a, 5);
	cout << "��С���ǣ�" << min << endl;
}

int FindMin(int* a, int length)
{
	if (a == nullptr || length <= 0)
	{
		cout << "��������" << endl;
		return 0;
	}
	int start = 0;
	int  end = length - 1;
	int mid = start;
	if (1 == end - start)
	{
		if (a[end] > a[start])
		{
			return a[start];
		}
		else
		{
			return a[end];
		}
	}
	while (end - start > 1 && a[start] >= a[end])
	{
		int index = start;
		//int mid = (end-start+1)/ 2;
		mid = (start + end) / 2;//��ʾÿ�β��ҵ��м�ֵ�������������е�λ��
		if (a[start] == a[mid] && a[end] == a[mid])//��start��end��midָ���������ͬʱ��ֻ��˳�����
		{
			return MinInOrder(a, start, end);
		}

	if (a[mid] >= a[mid - 1])
	{
		
		start = mid;
	}
	if (a[mid ] <= a[mid+ 1] )
	{
		end = mid;
	}
	}
	return a[mid];
	
}

int MinInOrder(int* a, int start, int end)
{
	int result = a[start];
	for (int i = start + 1; i <= end; i++)
	{
		if (result > a[i])
		{
			result = a[i];
		}
	}
	return result;
}
