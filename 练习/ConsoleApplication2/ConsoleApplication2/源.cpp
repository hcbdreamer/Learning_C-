#include<iostream>  
#include<algorithm>  
using namespace std;
int main()
{
	int n, m, i = 0;
	int arr[2000000] = { 0 };
	scanf("%d", &n);
	while (getchar() != '\n')//����س�ʱ����һ�����룬����  
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
	sort(arr, arr + n + m); //����  
	printf("%d", arr[(n + m - 1) / 2]);//����λ��  
	return 0;
}