#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if (nums.size() == 0) return 1;
        if (nums.size() == 1) return (nums[0]<=0?1:(nums[0]>1?1:nums[0]+1));

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()),nums.end());
                
        int left = 0;
        int right = nums.size()-1;
        int middle = 0;
        
        if (nums[right] < 0) return 1;
        if (nums[left] > 1) return 1;
        
        //find the range of positive numbers
        while (left < right)
        {
            middle = (left + right) >> 1;
            if (nums[middle] < 0)
            {
                left = middle + 1;
            }
            else if (nums[middle] > 0)
            {
                //left = (left + middle) >> 1;
                right = middle;
            }
            else
            {
                while(nums[middle] == 0) ++middle;
                left = middle;
            }
        }
        //cout<<"stage1 L="<<left<<",R="<<right<<endl;
        
        int base = left;
        right = nums.size()-1;
        //cout<<"stage2 L="<<left<<",R="<<right<<endl;
        while (left+1 < right)
        {
            middle = (left + right) >> 1;
            if (nums[middle] == (middle+1-base))
            {
                //no missing integers in the group of left to middle
                left = middle;
            }
            else
            {
                right = middle;
            }
        }
        //cout<<"stage3 L="<<left<<",R="<<right<<endl;
      
        if (left > 0 && nums[left-1] <= 0 && nums[left] > 1) return 1;
        else if (nums[left]+1 == nums[right]) return nums[right]+1;
        else return nums[left]+1;
    }
};

#if 0
int main()
{
    Solution sol;
    //vector<int> nums = {-4,-3,-2,-1,1,2,3,4,5,6,7,8,9,11};
    vector<int> nums;
    nums = {-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,6,9};
    assert(4==sol.firstMissingPositive(nums));
    nums = {-8,1,2,3,4,5,6,7,9,10};
    assert(8==sol.firstMissingPositive(nums));
    nums = {1,2,3,4,5,6,7,9,10};
    assert(8==sol.firstMissingPositive(nums));
    nums = {1,2,3,4,5,6,7,8,9,10};
    assert(11==sol.firstMissingPositive(nums));
    nums = {};
    assert(1==sol.firstMissingPositive(nums));
    nums = {2};
    assert(1==sol.firstMissingPositive(nums));
    nums = {1};
    assert(2==sol.firstMissingPositive(nums));
    nums = {1,2,0};
    assert(3==sol.firstMissingPositive(nums));
    nums = {3,4,-1,1};
    assert(2==sol.firstMissingPositive(nums));
    nums = {7,8,9,11,12};
    assert(1==sol.firstMissingPositive(nums));
    nums = {1,7,8,9,11,12};
    assert(2==sol.firstMissingPositive(nums));
    nums = {0,7,8,9,11,12};
    assert(1==sol.firstMissingPositive(nums));
    nums = {0,1,7,8,9,11,12};
    assert(2==sol.firstMissingPositive(nums));
    nums = {0,1,1,2,2};
    assert(3==sol.firstMissingPositive(nums));
    nums = {0,1,1,1,1,1,1,1,2,3,3,5,5,5,5,4};
    assert(6==sol.firstMissingPositive(nums));
    
    cout<<"ALL PASS!"<<endl;

    return 0;
}
#endif