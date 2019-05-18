#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        const int upper = 2;
        if (nums.size() <= 1)
            return;
 
        vector<int> vpos(3, -1);
        vpos[nums[0]] = 0;
        for (int i  = 1; i < nums.size(); ++i)
        {
            if (vpos[nums[i]] == -1)
                vpos[nums[i]] = i;
            if (nums[i] < nums[i-1])
            {
                for (int k = nums[i]+1; k <= upper; ++k)
                {
                    if (vpos[k] >= 0) //swap nums[i] to the number in the position vpos[k]
                                      //k could be 1 to upper
                    {
                        swap(nums[vpos[k]], nums[i]);
                        //not to update vpos, e.g. swap idx_2 and idx_4 : [0,1,2,2,1,0]
                        //update vpos, e.g. swap idx_1 and idx_3 : [0,2,2,1]
                        vpos[nums[vpos[k]]] = min(vpos[nums[vpos[k]]], vpos[k]);
                        //update vpos[2] to vpos[2]+1, e.g. swap idx_2 and idx_4 : [0,1,2,2,1,0]
                        vpos[k] = min(vpos[k]+1, i);
                        --i;
                        break;
                    }
                }
            }
        }
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    
    vector<int> nums;
    //nums = {2,0,2,1,1,0};
    //nums = {0,0,1,1,1,0};
    //nums = {0,2,1,1,1,0};
    //nums = {};
    //nums = {2};
    //nums = {0};
    //nums = {0,2};
    //nums = {2,0};
    nums = {2,1,0};
    sol->sortColors(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
    free(sol);
}
#endif
