#include <iostream>
#include <vector>
#include <cassert>
#include <cmath> //pow

using namespace std;

class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        glen = nums.size();
        if (glen == 0) return {{}};
        vans.clear();
        vtmp.clear();
        
        dfs(0, nums);
        
        return vans;
    }
private:
    int glen = 0;
    vector<vector<int>> vans;
    vector<int> vtmp;
    void dfs(int idx, vector<int>& nums)
    {
        if (idx == glen)
        {
            vans.push_back(vtmp);
            return;
        }
        //select element
        vtmp.push_back(nums[idx]);
        dfs(idx+1, nums);
        vtmp.pop_back();
        //ignore element
        dfs(idx+1,nums);
    }
};

#if 1 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    vector<int> nums;
    vector<vector<int>> vans;
    
    nums = {1,2,3};
    nums = {};
    nums = {1};
    nums = {1,2,3,4,5,6,7,99};
    vans = sol->subsets(nums);
    
    assert(pow(2,nums.size()) == vans.size());
    for (int i = 0; i < vans.size(); ++i)
    {
        cout<<"idx "<<i<<endl;
        for (int k = 0; k < vans[i].size(); ++k)
            cout<<vans[i][k]<<" ";
        cout<<endl;
    }
    
    free(sol);
}
#endif
