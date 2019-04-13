#include <iostream>
#include <vector>
#include <algorithm>
//#include <cassert>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        if (target <= 0) return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vans = dfs2(candidates, target, 0);
        for (int i = 0; i < vans.size(); ++i)
            sort(vans[i].begin(), vans[i].end());
        return vans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if (target <= 0) return vector<vector<int>>();

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vans = dfs(candidates, target, 0);
        for (int i = 0; i < vans.size(); ++i)
            sort(vans[i].begin(), vans[i].end());
        return vans;
    }
private:
    vector<vector<int>> dfs2(vector<int>& vcan, int target, int idx)
    {
        if (target < 0) return vector<vector<int>>();
                
        vector<vector<int>> vans;
        for (int i = idx; i < vcan.size(); ++i)
        {
            if ((i > idx) && (vcan[i-1] == vcan[i]))
                continue;
                
            if ((target - vcan[i]) < 0)
            {
                break;
            }
            else if ((target - vcan[i]) == 0)
            {
                vans.push_back(vector<int>());
                vans[vans.size()-1].push_back(vcan[i]);
                return vans;
            }
            else if ((target - vcan[i] > 0) && (i+1 < vcan.size())) 
            {
                vector<vector<int>> vtmp = dfs2(vcan, target - vcan[i], i+1);
                for (int k = 0; k < vtmp.size(); ++k)
                {
                    vans.push_back(vtmp[k]);
                    vans[vans.size()-1].push_back(vcan[i]);
                }
            }
        }
        return vans;
    }

    vector<vector<int>> dfs(vector<int>& vcan, int target, int idx)
    {
        if (target < 0) return vector<vector<int>>();
                
        vector<vector<int>> vans;
        for (int i = idx; i < vcan.size(); ++i)
        {
            if ((target - vcan[i]) < 0)
            {
                break;
            }
            else if ((target - vcan[i]) == 0)
            {
                vans.push_back(vector<int>());
                vans[vans.size()-1].push_back(vcan[i]);
                return vans;
            }
            else if (target - vcan[i] > 0) 
            {
                vector<vector<int>> vtmp = dfs(vcan, target - vcan[i], i);
                for (int k = 0; k < vtmp.size(); ++k)
                {
                    vans.push_back(vtmp[k]);
                    vans[vans.size()-1].push_back(vcan[i]);
                }
            }
        }
        return vans;
    }
};

#if 0
int main()
{
    Solution sol;
    //vector<int> vcan = {2,3,6,7};
    //vector<int> vcan = {2,3,5};
    //vector<int> vcan = {2,3,5,10,9,8,7};
    //vector<int> vcan = {10,1,2,7,6,1,5};
    //vector<vector<int>> vans = sol.combinationSum(vcan,7);
    //vector<vector<int>> vans = sol.combinationSum(vcan,8);
    //vector<vector<int>> vans = sol.combinationSum(vcan,10);
    //for (int i = 0; i < vans.size(); ++i)
    //{
    //    for (int k = 0; k < vans[i].size(); ++k)
    //        cout<<vans[i][k]<<" ";
    //    cout<<endl;
    //}
    vector<int> vcan2 = {10,1,2,7,6,1,5};
    //vector<int> vcan2 = {1,2,2,2,2,2,5};
    vector<vector<int>> vans2 = sol.combinationSum2(vcan2,8);
    //vector<vector<int>> vans2 = sol.combinationSum2(vcan2,5);
    for (int i = 0; i < vans2.size(); ++i)
    {
        for (int k = 0; k < vans2[i].size(); ++k)
            cout<<vans2[i][k]<<" ";
        cout<<endl;
    }
    return 0;
}
#endif