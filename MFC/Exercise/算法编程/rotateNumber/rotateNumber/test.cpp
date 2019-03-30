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
	cout << "最小数是：" << min << endl;
}

int FindMin(int* a, int length)
{
	if (a == nullptr || length <= 0)
	{
		cout << "输入有误！" << endl;
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
		mid = (start + end) / 2;//表示每次查找的中间值，在整个数组中的位置
		if (a[start] == a[mid] && a[end] == a[mid])//当start与end与mid指向的数字相同时，只能顺序查找
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
