#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int len = strs.size();
        
        if (len == 0) return {{}};
        if (len == 1) return {{strs}};

        vector<vector<string>> vsans;
        unordered_map<string, int> map;
        vector<string> ssort = strs;
        
        for (int i = 0; i < len; ++i)
        {
            sort(ssort[i].begin(), ssort[i].end());
            auto it = map.find(ssort[i]);
            if (it == map.end())
            {
                vsans.push_back(vector<string>());
                vsans[vsans.size()-1].push_back(strs[i]);
                map[ssort[i]] = vsans.size()-1;
            }
            else
            {
                vsans[it->second].push_back(strs[i]);
            }
        }
        return vsans;
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    vector<string> strs;
    vector<vector<string>> vsans; 

    vsans = sol->groupAnagrams(strs);

    strs = {""};
    vsans = sol->groupAnagrams(strs);

    strs = {"xx"};
    vsans = sol->groupAnagrams(strs);

    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vsans = sol->groupAnagrams(strs);
    
    strs = {"ironman", "maniron", "irontony", "tonystark", "tonystark", "starktony", "spiderman", "miaronn"};
    vsans = sol->groupAnagrams(strs);
    
    for (int i = 0; i < vsans.size(); ++i)
    {
        for (int k = 0; k < vsans[i].size(); ++k)
        {
            cout<<vsans[i][k]<<" ";
        }
        cout<<endl;
    }
    
    free(sol);
}
#endif