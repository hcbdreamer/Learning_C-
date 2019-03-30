#include <iostream>
using namespace std;
int fill_array(double ar[], int limit);
void show_array(double ar[], int limit);
int fill_array2(int ar2[][2], int size);
void show_array2(int ar2[][2], int size);

void main()
{
	const int max=5,max2=2;
	double ar[max];
	int ar2[max2][2];
	fill_array(ar, max);
	show_array(ar, max);
	fill_array2(ar2, max2);
	show_array2(ar2, max2);
}

int fill_array(double ar[], int limit)
{
	int i;
	double temp;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value # " << i + 1 << ": ";
		cin >> temp;
		ar[i] = temp;
	}
	return i;
}

void show_array(double ar[], int limit)
{
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Property # " << i << " is : ";
		cout << ar[i]<<endl;
	}
}
int fill_array2(int ar2[][2], int size)
{
	int r,c,temp;
	for (r = 0; r < size; r++)
	{
		for (c = 0; c < 2; c++)
			//cout << "input temp";
		{
			cin >> temp;
			ar2[r][c] = temp;
		}
	}
	return c;
}
void show_array2(int ar2[][2], int size)
{
	int r, c;
	for (r = 0; r < size; r++)
	{
		for (c = 0; c < 2; c++)
		{
			cout << "ar2[" << r << "][" << c << "] is " ;
			cout << ar2[r][c]<<endl;
		}
	}
}