#include<iostream>
using namespace std;

//��������
void swap(int* a, int* b);
//ð������
int BubbleSort(int* a, int length);
//��ѡ������
int SimpleSort(int* a, int length);
//��������
int InsertSort(int* a, int length);
//��������
void QuickSort(int* a, int low, int high);
//�鲢�㷨
void MergeSort(int*a, int start, int end, int* result);
void Merge(int* a, int start, int end, int* result);

int main()
{
	int a[] = { 9, 1, 6, 2, 3, 4, 8 };
	int index = 0;
	int length = sizeof(a) / sizeof(*a);
   /* index=BubbleSort(a, length);
	cout << "ð������������ǣ�";
	index = SimpleSort(a, length);
	cout << "������������ǣ�";*/
	/*index = InsertSort(a, length);
	cout << "ֱ�Ӳ�������������ǣ�";*/
	/*QuickSort(a, 0, 6);
	cout << "��������������ǣ�";*/
	int result[7];
	MergeSort(a, 0, 6,result);
	cout << "��������������ǣ�";
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	cout << "���鳤���ǣ�" << length << endl;
	cout << "��������ǣ�" << index << endl;
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
		cout << "��������" << endl;
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
			while (first < end&&a[end] >= key)//��������Ѱ��С��key��ֵ
			{
				--end;
			}
			swap(a[first], a[end]);
			while (first < end&&a[first] <= key)//������Ѱ�Ҵ���Keyֵ��ֵ
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
		//�������������䣬�ֱ�������������������
		MergeSort(a, start, (end - start + 1) / 2 + start, result);
		MergeSort(a, (end - start + 1) / 2 + start + 1, end, result);
		//��ʼ�鲢�Ѿ��ź����start��end֮�������
		Merge(a, start, end, result);
		//�����������鸴�Ƶ�ԭ������
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
	//�Էֱ��Ѿ��ź�������������������кϲ�
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