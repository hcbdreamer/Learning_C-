#include<map>
#include<algorithm>
#include<vector>
using namespace std;
class number
{
public:
	bool repeat(int num[], int length, int* repeatnumber);
	vector<int> repeat2(int num[], int length);
};


/*bool number::repeat(int num[], int length, int* repeatnumber)
{
	if (length <= 1 || num == nullptr)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (num[i] > length - 1 || num[i] < 0)
			return false;
	}
	int changenum=0;
	for (int i = 0; i < length; ++i)
	{
		while(num[i] != i)
		{
			if (num[i] == num[num[i]])
			{
                *repeatnumber = num[i];
				return true;
			}
			else
			{
				changenum = num[i];
				num[i] = num[changenum];
				num[changenum] = changenum;
			}
		}
	}
	return false;
}*/

/*bool number::repeat(int num[], int length, int* repeatnumber)
{
	if (length <= 1 || num == nullptr)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (num[i] > length - 1 || num[i] < 0)
			return false;
	}
	map<int, int>x1;
	for (int i = 0; i < length; ++i)
	{
		x1[num[i]]++;
	}
	map<int, int>::iterator iter;
	for (iter = x1.begin(); iter != x1.end(); iter++)
	{
		if (iter->second != 1)
		{
			*repeatnumber = iter->second;
			return true;
		}
	}
	return false;

	}*/
vector<int> number::repeat2(int num[], int length)
{
	vector<int>repeatnum;
	if (length <= 1 || num == nullptr)
	{
		return repeatnum;
	}
	for (int i = 0; i < length; ++i)
	{
		if (num[i] > length - 1 || num[i] < 0)
			return repeatnum;
	}
	map<int, int>x1;
	for (int i = 0; i < length; ++i)
	{
		x1[num[i]]++;
	}
	map<int, int>::iterator iter;
	for (iter = x1.begin(); iter != x1.end(); iter++)
	{
		if (iter->second != 1)
		{
			repeatnum.push_back(iter->first);
		}
	}
	return repeatnum;
}