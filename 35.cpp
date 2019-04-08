#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return -1;
        
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
            else if (nums[middle-1] <= target && nums[middle] >= target)
            {
                first = middle-1;
                last = middle;
                break;
            }
            else
            {
                break;
                //return -1;
            }
            middle = (first + last) >> 1;
        }

        if (target == nums[first])
        {
            return first;
        }
        else if (target == nums[last])
        {
            return last;
        }
        else if (target < nums[first])
        {
            return (first-1>0)?(first-1):0;
        }
        else if (target > nums[last])
        {
            return last+1;
        }
        else if (target > nums[first])
        {
            return first+1;
        }
        else
        {
            return -1;
        }
    }
};

#if 0
int main()
{
	Solution sol;
	vector<int> nums;
	nums = {0,1,2,4,5,6,7,8,9,10};
	cout<<"ans 3="<<sol.searchInsert(nums,3)<<endl;
	assert(3==sol.searchInsert(nums,3));
	cout<<"ans 10="<<sol.searchInsert(nums,22)<<endl;
	assert(10==sol.searchInsert(nums,22));
	
	nums.clear();
	nums = {1,2,4,6,7};
	cout<<"ans 2="<<sol.searchInsert(nums,3)<<endl;
	assert(2==sol.searchInsert(nums,3));
	
	nums.clear();
	nums = {1,3,5,6};
	cout<<"ans 2="<<sol.searchInsert(nums,5)<<endl;
	assert(2==sol.searchInsert(nums,5));
	cout<<"ans 1="<<sol.searchInsert(nums,2)<<endl;
	assert(1==sol.searchInsert(nums,2));
	cout<<"ans 4="<<sol.searchInsert(nums,77)<<endl;
	assert(4==sol.searchInsert(nums,77));
	cout<<"ans 0="<<sol.searchInsert(nums,-100)<<endl;
	assert(0==sol.searchInsert(nums,-100));
	cout<<"ans 0="<<sol.searchInsert(nums,0)<<endl;
	assert(0==sol.searchInsert(nums,0));
	cout<<"ans 2="<<sol.searchInsert(nums,4)<<endl;
	assert(2==sol.searchInsert(nums,4));

	nums.clear();
    nums = {-100,-99,-5,0,5,7,8,10,200,300,500,700,999,1000};
	cout<<"ans 12="<<sol.searchInsert(nums,999)<<endl;
	assert(12==sol.searchInsert(nums,999));
	cout<<"ans 8="<<sol.searchInsert(nums,200)<<endl;
	assert(8==sol.searchInsert(nums,200));
	cout<<"ans 7="<<sol.searchInsert(nums,10)<<endl;
	assert(7==sol.searchInsert(nums,10));
	cout<<"ans 3="<<sol.searchInsert(nums,-3)<<endl;
	assert(3==sol.searchInsert(nums,-3));

	nums.clear();
	cout<<"ans -1="<<sol.searchInsert(nums,5)<<endl;
    assert(-1==sol.searchInsert(nums,5));
    
	nums = {-999,-3,-2,-1};
	cout<<"ans 4="<<sol.searchInsert(nums,0)<<endl;
	assert(4==sol.searchInsert(nums,0));
	cout<<"ans 1="<<sol.searchInsert(nums,-3)<<endl;
	assert(1==sol.searchInsert(nums,-3));
	cout<<"ans 0="<<sol.searchInsert(nums,-1111)<<endl;
	assert(0==sol.searchInsert(nums,-1111));

    return 0;
}
#endif