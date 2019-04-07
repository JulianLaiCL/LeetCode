#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return -1;
        int last = nums.size()-1;
        int first = 0;
        int middle = (first + last) >> 1;
        while ((first < last) && (first != middle) && (last != middle))
        {
            //case 1 : normal case
            if (nums[first] <= nums[middle-1] && nums[middle] <= nums[last])
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
                    return -1;
            }
            //case 2
            else if (nums[first] <= nums[middle-1] && nums[middle] >= nums[last])
            {
                if (nums[first] <= target && nums[middle-1] >= target)
                {
                    last = middle-1;
                }
                else
                {
                    first = middle;
                }
            }
            //case 3
            else if (nums[first] >= nums[middle-1] && nums[middle] <= nums[last])
            {
                if (nums[middle] <= target && nums[last] >= target)
                {
                    first = middle;
                }
                else
                {
                    last = middle-1;
                }

            }
            middle = (first + last) >> 1;
            //cout<<"target = "<<target<<"; first, last, middle,"<<first<<" "<<last<<" "<<middle<<", nums["<<first<<"]="<<nums[first]<<",nums["<<last<<"]="<<nums[last]<<",nums["<<middle<<"]="<<nums[middle]<<endl;
        }
        if (target == nums[first]) return first;
        if (target == nums[last]) return last;
        if (target == nums[middle]) return middle;
        return -1;
    }
};

#if 0
int main()
{
	Solution sol;
	vector<int> nums = {4,5,6,7,8,9,10,0,1,2};
    cout<<"ans 7="<<sol.search(nums, 0)<<endl;
    cout<<"ans -1="<<sol.search(nums, 3)<<endl;
	vector<int> nums2 = {8,9,10,0,1,2,4,5,6,7};
    cout<<"ans 3="<<sol.search(nums2, 0)<<endl;
    cout<<"ans -1="<<sol.search(nums2, 3)<<endl;
	vector<int> nums3 = {0,1,2,4,5,6,7,8,9,10};
    cout<<"ans 0="<<sol.search(nums3, 0)<<endl;
    cout<<"ans -1="<<sol.search(nums3, 3)<<endl;
	vector<int> nums4 = {5,6,7,8,9,10,11,15,20,99,1001,4567,0,1,2,4};
    cout<<"ans 12="<<sol.search(nums4, 0)<<endl;
    cout<<"ans 9="<<sol.search(nums4, 99)<<endl;
    cout<<"ans 11="<<sol.search(nums4, 4567)<<endl;
    cout<<"ans 10="<<sol.search(nums4, 1001)<<endl;
	vector<int> nums5 = {1001,4567,0,1,2,4,5,6,7,8,9,10,11,15,20,99};
    cout<<"ans 2="<<sol.search(nums5, 0)<<endl;
    cout<<"ans 15="<<sol.search(nums5, 99)<<endl;
    cout<<"ans 1="<<sol.search(nums5, 4567)<<endl;
    cout<<"ans 0="<<sol.search(nums5, 1001)<<endl;
	
	return 0;
}
#endif