#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return true;
        if (nums[0] == 0) return false;
        if (nums[0] >= (nums.size())) return true;

        int start = 0, end = 0, max = 0, step = 0;
        while (end < (nums.size()-1))
        {
            ++step;
            for (int i = start; i < (end+1); ++i)
                max = std::max(max, i+nums[i]);
            
            if (max == end)
                return false;
                
            start = end + 1;
            end = max;
        }
        //cout<<step<<endl;
        return true;
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    vector<int> nums;

    assert(sol->canJump(nums) == false);

    nums = {3,2,1,0,4};
    assert(sol->canJump(nums) == false);
    nums = {3,2,1,8,4,0,0,0,0,0,0,0,0,0,0,0};
    assert(sol->canJump(nums) == false);
    nums = {0};
    assert(sol->canJump(nums) == true);
    nums = {1};
    assert(sol->canJump(nums) == true);
    nums = {0,99,1,2,3,4};
    assert(sol->canJump(nums) == false);
    nums = {2,1,2,1,999};
    assert(sol->canJump(nums) == true);
    nums = {2,3,1,1,4};
    assert(sol->canJump(nums) == true);
    nums = {1,6,1,1,1,1,1,1,1,1};
    assert(sol->canJump(nums) == true);
    nums = {999,6,1,1,1,1,1,1,1,1};
    assert(sol->canJump(nums) == true);
    nums = {3,6,8,1,1,1,1,1,1,1};
    assert(sol->canJump(nums) == true);
    nums = {0,6,8,1,1,1,1,1,1,1};
    assert(sol->canJump(nums) == false);
    nums = {0,6,3,1,1,1,1,0,1,1};
    assert(sol->canJump(nums) == false);
    nums = {3,7,1,3,1,1,4,1,1,1};
    assert(sol->canJump(nums) == true);
    nums = {3,4,6,3,1,1,2,1,1,1};
    assert(sol->canJump(nums) == true);
    nums = {3,4,6,3,0,1,2,1,1,1};
    assert(sol->canJump(nums) == true);
    nums = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    assert(sol->canJump(nums) == true);
    cout<<"Test Case Passed!"<<endl;
    
    free(sol);
}
#endif