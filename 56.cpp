#include <iostream>
//#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> vans;
        int len = intervals.size();
        if (len == 0 || len == 1) return intervals;
        //it seems the input intervals are alwasy in the format of {min,max}
        //for (int i = 0; i < len; ++i)
        //    sort(intervals[i].begin(), intervals[i].end());
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>&a, const vector<int>&b){return a[0]<b[0];});
        int min = intervals[0][0], max = intervals[0][1];
        for (int i = 1; i < len; ++i)
        {
            if (intervals[i][0] >= min && intervals[i][0] <= max)
            {
                max = std::max(max,intervals[i][1]);
            }
            else
            {
                vans.push_back({min, max});
                min = intervals[i][0];
                max = intervals[i][1];
            }
        }
        vans.push_back({min, max});
        return vans;
    }
    void dump(vector<vector<int>>& vans)
    {
        for (int i = 0; i < vans.size(); ++i)
        {
            for (int k = 0; k< vans[i].size(); ++k)
                cout<<vans[i][k]<<" ";
            cout<<endl;
        }
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    //[[1,3],[2,6],[8,10],[15,18]]=>[[1,6],[8,10],[15,18]]
    //[[1,4],[4,5]]=>[[1,5]]
    vector<vector<int>> intervals;
    
    //intervals = {{9, 5},{4, 9},{1, 3},{5, 10},{5, 20},{3, 9}};
    intervals = {{1,3},{2,6},{8,10},{15,18}};
    intervals = {{1,4},{4,5}};
    intervals = {{1,4},{2,3}};
    //intervals = {{888,555}};
    
    //intervals = {{}}; //invalid input
    intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    //sort(intervals.begin(), intervals.end());
    vector<vector<int>> vans = sol->merge(intervals);
    sol->dump(vans);
    
    free(sol);
}
#endif
