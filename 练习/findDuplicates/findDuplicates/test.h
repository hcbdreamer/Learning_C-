#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution
{
public:
	vector<int>findDuplicates(vector<int>& nums)
	{
		vector<int> nums1;
		map<int, int>maplist;
		for (int i = 0; i < nums.size(); i++)
		{
			map<int, int >::iterator l_it2 ;
			if (maplist.begin()== maplist.end()){
				maplist.insert(pair<int, int>(nums[0], 1));
			}
			for (l_it2 = maplist.begin(); l_it2 != maplist.end(); l_it2++)
			{   
				map<int, int >::iterator l_it1;
				l_it1 = maplist.find(nums[i]);
				if (l_it1 == maplist.end())
				{
					maplist.insert(pair<int, int>(nums[i], 1));
				}
				else
				{
					maplist.insert(pair<int, int>(nums[i], 2));
				}
			}

		}
		/*for (int i : nums)
		{
			if (maplist.count(i)==0)
			    maplist.insert(pair<int,int>(i,0));
			maplist[i]++;
		}*/
		/*for (int j : nums)
		{
			if (maplist[j]>1)
		    nums1.push_back(j);
		}
	    */
		map<int, int >::iterator l_it;
		for (l_it = maplist.begin(); l_it != maplist.end(); l_it++)
		{
			if (l_it->second >1)
			{
				nums1.push_back(l_it->first);
			}
		}
		return nums1;
	}
};