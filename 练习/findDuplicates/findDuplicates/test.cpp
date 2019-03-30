#include"test.h"

int main()
{
	Solution test;
	
	vector<int>nums1;
	int a[8] = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int>nums(a,a+8);
	nums1=test.findDuplicates(nums);
	for (int i = 0; i < nums1.size(); i++)
	{
		cout << nums1[i];
	}
}