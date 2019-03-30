#include<iostream>
using namespace std;

int Getsize(int data[]);
int main(){
	int data1[] = { 1, 2, 3, 4, 5 };
	int* data2 = data1;
	int size1 = sizeof(data1);//sizeof求数组大小 
	int size2 = sizeof(data2);//在32位系统上指针占四个字节
	int size3 = Getsize(data1);//数组作为参数传递时，数组自动退化为同类型指针
	cout << "size1 is " << size1 << endl;
	cout << "size2 is " << size2 << endl;
	cout << "size3 is " << size3 << endl;
}

int Getsize(int data[])
{
	return sizeof(data);
}