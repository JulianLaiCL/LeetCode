#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return {-1,-1};
        
        vector<int> vans;
        int last = nums.size()-1;
        int first = 0;
        int middle = (first + last) >> 1;
        while ((first+1) < last)
        {
            if (nums[first] <= target && nums[middle-1] >= target)
            {
                last = middle-1;
            }
            else if (nums[middle] <= target && nums[last] >= target)
            {
                first = middle;
            }
            else
            {
                return {-1,-1};
            }
            middle = (first + last) >> 1;
        }

        if (target == nums[first])
        {
            vans.push_back(first);
        }
        else if (target == nums[middle])
        {
            vans.push_back(middle);
        }
        else if (target == nums[last])
        {
            vans.push_back(last);
        }
        else
        {
            return {-1,-1};
        }

        last = nums.size()-1;
        first = vans[0];
        middle = (first + last) >> 1;
        while ((first+1) < last)
        {
            if (nums[middle] <= target && nums[last] >= target)
            {
                first = middle;
            }
            else if (nums[first] <= target && nums[middle-1] >= target)
            {
                last = middle-1;
            }
            else
            {
                return {-1,-1};
            }
            middle = (first + last + 1) >> 1;
        }

        if (target == nums[last])
        {
            vans.push_back(last);
        }
        else if (target == nums[middle])
        {
            vans.push_back(middle);
        }
        else if (target == nums[first])
        {
            vans.push_back(first);
        }
        else
        {
            return {-1,-1};
        }

        return vans;
    }
};

#if 0
int main()
{
	Solution sol;
	vector<int> nums;
	vector<int> vans;
	nums = {0,1,2,4,5,6,7,8,8,8,9,10};
	vans = sol.searchRange(nums,8);
	cout<<"ans 7,9="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	
	nums.clear();
	nums = {5,7,7,8,8,10};
	vans = sol.searchRange(nums,8);
	cout<<"ans 3,4="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	vans = sol.searchRange(nums,6);
	cout<<"ans -1,-1="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();

	nums.clear();
    nums = {5,7,7,8,8,10,200,200,300,300,300,300,300,500,700,999,999,999,999,999,999,999,999,999,999,1000};
	vans = sol.searchRange(nums,999);
	cout<<"ans 15,24="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	vans = sol.searchRange(nums,200);
	cout<<"ans 6,7="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	vans = sol.searchRange(nums,10);
	cout<<"ans 5,5="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	vans = sol.searchRange(nums,5);
	cout<<"ans 0,0="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	
	nums.clear();
	vans = sol.searchRange(nums,5);
	cout<<"ans -1,-1="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();

	nums = {-999,-3,-3,-3,-3,-2,-1};
	vans = sol.searchRange(nums,0);
	cout<<"ans -1,-1="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	vans = sol.searchRange(nums,-3);
	cout<<"ans 1,4="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	vans = sol.searchRange(nums,-1111);
	cout<<"ans -1,-1="<<vans[0]<<","<<vans[1]<<endl;
	vans.clear();
	
    return 0;
}
#endif