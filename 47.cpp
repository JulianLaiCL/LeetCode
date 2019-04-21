#include <iostream>
#include <cassert>
#include <vector>
//#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        len = nums.size();
        if (len == 0) return {};
        if (len == 1) return {{nums[0]}};

        ans.clear();
        recpermuteUnique(nums, 0);
        return ans;
    }
    void dump(vector<vector<int>>& ans)
    {
        //size is n!/(k!*m!...) where n is the size of ans and k and m are the repeated number of each group
        cout<<"sizeof ans is "<<ans.size()<<", dump ans: "<<endl;
        for (int i = 0; i < ans.size(); ++i)
        {
            for (int k = 0; k < ans[i].size(); ++k)
                cout<<ans[i][k]<<" ";
            cout<<endl;
        }
    }
private:
    vector<vector<int>> ans;
    int len;
    void recpermuteUnique(vector<int>& nums, int pos)
    {
        unordered_map<int, int> map;
        
        if (pos == len-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for (int i = pos; i < len; ++i)
        {
            //use unordered_map to 46.cpp for the condition of 47.cpp
            if (map[nums[i]]) continue;
            map[nums[i]]++;

            std::swap(nums[i], nums[pos]);
            recpermuteUnique(nums, pos+1);
            std::swap(nums[pos], nums[i]);
        }
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    vector<int> nums;
    vector<vector<int>> ans;

    ans = sol->permuteUnique(nums);
    sol->dump(ans);
    nums = {0};
    ans = sol->permuteUnique(nums);
    sol->dump(ans);
    nums = {1};
    ans = sol->permuteUnique(nums);
    sol->dump(ans);
    nums = {1,1,2,1};
    ans = sol->permuteUnique(nums);
    sol->dump(ans);
    nums = {4,5,6,4,1};
    ans = sol->permuteUnique(nums);
    sol->dump(ans);
    nums = {1,1,5,5,1};
    ans = sol->permuteUnique(nums);
    sol->dump(ans);

    free(sol);
}
#endif