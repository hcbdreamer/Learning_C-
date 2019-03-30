#include<iostream>
using namespace std;

//交换次序
void swap(int* a, int* b);
//冒泡排序
int BubbleSort(int* a, int length);
//简单选择排序
int SimpleSort(int* a, int length);
//插入排序
int InsertSort(int* a, int length);
//快速排序
void QuickSort(int* a, int low, int high);
//归并算法
void MergeSort(int*a, int start, int end, int* result);
void Merge(int* a, int start, int end, int* result);

int main()
{
	int a[] = { 9, 1, 6, 2, 3, 4, 8 };
	int index = 0;
	int length = sizeof(a) / sizeof(*a);
   /* index=BubbleSort(a, length);
	cout << "冒泡排序后数组是：";
	index = SimpleSort(a, length);
	cout << "简单排序后数组是：";*/
	/*index = InsertSort(a, length);
	cout << "直接插入排序后数组是：";*/
	/*QuickSort(a, 0, 6);
	cout << "快速排序后数组是：";*/
	int result[7];
	MergeSort(a, 0, 6,result);
	cout << "快速排序后数组是：";
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	cout << "数组长度是：" << length << endl;
	cout << "计算次数是：" << index << endl;
	/*cout << a << endl << &a << endl << &a[0]<<endl<<&(*a)<<endl;
	cout << sizeof(a)<<endl<<sizeof(&a)<<endl<<sizeof(*a)<<endl;
	cout << a + 1 << endl << &a + 1 << endl;*/
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int BubbleSort(int* a, int length)
{
	if (!a||length<0)
	{
		cout << "输入有误！" << endl;
		return 0;
	}
	int index = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				index++;
			}
		}
	}
	return index;
}
int SimpleSort(int* a, int length)
{
	int min, index = 0;
	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
				index++;
			}
		}
		swap(a[i], a[min]);
	}
	return index;
}
int InsertSort(int* a, int length)
{
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			for (int j = i - 1; a[j] > temp; j--)
			{
				a[j + 1] = a[j];
				a[j] = temp;
				index++;
			}
		}
	}
		return index;
}

void QuickSort(int* a, int low, int high)
{
	if (low < high)
	{
       int key = a[low];
		int first = low;
		int end = high;
		while (first < end)
		{
			while (first < end&&a[end] >= key)//从右向左寻找小于key的值
			{
				--end;
			}
			swap(a[first], a[end]);
			while (first < end&&a[first] <= key)//从左到右寻找大于Key值的值
			{
				++first;
			}
			swap(a[end], a[first]);
		}
		a[first] = key;
		QuickSort(a, low, first - 1);
		QuickSort(a, first + 1, high);
	}
		
}

void MergeSort(int*a, int start, int end, int* result)
{
	if (1 == end - start)
	{
		if (a[start]>a[end])
		{
			swap(a[start], a[end]);
		}
		return;
	}
	else if (0 == start - end)
	{
		return;
	}
	else
	{
		//继续划分子区间，分别对左右子区间进行排序
		MergeSort(a, start, (end - start + 1) / 2 + start, result);
		MergeSort(a, (end - start + 1) / 2 + start + 1, end, result);
		//开始归并已经排好序的start到end之间的数据
		Merge(a, start, end, result);
		//将排序后的数组复制到原数组中
		for (int i = start; i <= end; ++i)
		{
			a[i] = result[i];
		}
	}

}

void Merge(int* a, int start, int end, int* result)
{
	int leftlength = (end - start + 1) / 2 + 1;
	int leftindex = start;
	int rightindex = start + leftlength;
	int resultindex = start;
	//对分别已经排好序的左区间和右区间进行合并
	while (leftindex < leftlength + start&&rightindex < end + 1)
	{
		if (a[leftindex] < a[rightindex])
		{
			result[resultindex++] = a[leftindex++];
		}
		else
		{
			result[resultindex++] = a[rightindex++];
		}

	}
	while (leftindex < leftlength)
	{
			result[resultindex++] = a[leftindex++];
	}
	while (rightindex<end+1)
	{
			result[resultindex++] = a[rightindex++];
	}
}