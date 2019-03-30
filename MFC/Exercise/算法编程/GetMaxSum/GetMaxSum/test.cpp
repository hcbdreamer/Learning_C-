#include"test.h"
#include<iostream>
using namespace std;

int main()
{
	sum sum;
	int A[5] = { 1, 2 ,-1,2,-2};
	int maxsum=0;
	maxsum=sum.GetMaxSum(A, 5);
	cout << "MaxSum is " << maxsum << endl;
}