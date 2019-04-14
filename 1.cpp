#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if (nums.size() < 2) return {};
        
        unordered_map<int,int> mymap;
        //for (int i = 0; i < nums.size(); ++i)
        //    mymap[nums[i]] = i;
            
        int val = 0, idx = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            val = target - nums[i];
            //if (mymap[val] == 0)
            if (mymap.find(val) != mymap.end())
                return {mymap[val], i};			
            mymap[nums[i]] = i;
        }
        return {};
    }
};

#if 0
int main()
{
    Solution sol;
    //vector<int> nums = {1,2,4,7,11,15};
    //vector<int> vans = sol.twoSum(nums, 9);
    //vector<int> nums = {1,3,4,2};
    //vector<int> nums = {3,3};
    //vector<int> vans = sol.twoSum(nums, 6);
    vector<int> nums = {2,7,9,11,15};
    vector<int> vans = sol.twoSum(nums, 17);
    if (vans.size())
    {
        cout<<"ans="<<vans[0]<<","<<vans[1]<<endl;
    }
    return 0;
}
#endif