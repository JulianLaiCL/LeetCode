#include <iostream>
#include <vector>
#include <algorithm>
//#include <cassert>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if (target <= 0) return vector<vector<int>>();

        sort(candidates.begin(), candidates.end());//, greater<int>());
        vector<vector<int>> vans = dfs(candidates, target, 0);
        for (int i = 0; i < vans.size(); ++i)
            sort(vans[i].begin(), vans[i].end());
        return vans;
    }
private:
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
    //vector<int> vcan = {2,3,6,7};
    //vector<int> vcan = {2,3,5};
    vector<int> vcan = {2,3,5,10,9,8,7};
    Solution sol;
    //vector<vector<int>> vans = sol.combinationSum(vcan,7);
    //vector<vector<int>> vans = sol.combinationSum(vcan,8);
    vector<vector<int>> vans = sol.combinationSum(vcan,10);
    for (int i = 0; i < vans.size(); ++i)
    {
        for (int k = 0; k < vans[i].size(); ++k)
            cout<<vans[i][k]<<" ";
        cout<<endl;
    }
    return 0;
}
#endif