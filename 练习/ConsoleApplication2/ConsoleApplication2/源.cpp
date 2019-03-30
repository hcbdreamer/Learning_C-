#include<iostream>  
#include<algorithm>  
using namespace std;
int main()
{
	int n, m, i = 0;
	int arr[2000000] = { 0 };
	scanf("%d", &n);
	while (getchar() != '\n')//输入回车时结束一行输入，换行  
	{
		scanf("%d", &arr[i]);
		i++;
	}
	scanf("%d", &m);
	while (getchar() != '\n')
	{
		scanf("%d", &arr[i]);
		i++;
	}
	sort(arr, arr + n + m); //排序  
	printf("%d", arr[(n + m - 1) / 2]);//求中位数  
	return 0;
}