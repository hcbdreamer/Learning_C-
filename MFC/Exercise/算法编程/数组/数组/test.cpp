#include<iostream>
using namespace std;

int Getsize(int data[]);
int main(){
	int data1[] = { 1, 2, 3, 4, 5 };
	int* data2 = data1;
	int size1 = sizeof(data1);//sizeof�������С 
	int size2 = sizeof(data2);//��32λϵͳ��ָ��ռ�ĸ��ֽ�
	int size3 = Getsize(data1);//������Ϊ��������ʱ�������Զ��˻�Ϊͬ����ָ��
	cout << "size1 is " << size1 << endl;
	cout << "size2 is " << size2 << endl;
	cout << "size3 is " << size3 << endl;
}

int Getsize(int data[])
{
	return sizeof(data);
}