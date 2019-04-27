#include <iostream>
//#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (newInterval.size() == 0) return intervals;
        intervals.emplace_back(newInterval);
        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int len = intervals.size();
        if (len <2 ) return intervals;
        //it seems the input intervals are alwasy in the format of {min,max}
        //for (int i = 0; i < len; ++i)
        //    sort(intervals[i].begin(), intervals[i].end());
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>&a, const vector<int>&b){return a[0]<b[0];});
        int min = intervals[0][0], max = intervals[0][1];
        vector<vector<int>> vans;
        vector<int> tmp(2);
        for (int i = 1; i < len; ++i)
        {
            if (intervals[i][0] >= min && intervals[i][0] <= max)
            {
                max = std::max(max,intervals[i][1]);
            }
            else
            {
                tmp[0] = min;
                tmp[1] = max;
                vans.emplace_back(tmp);
                min = intervals[i][0];
                max = intervals[i][1];
            }
        }
        tmp[0] = min;
        tmp[1] = max;
        vans.emplace_back(tmp);
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
    vector<vector<int>> intervals;
    vector<int> newInterval;
    
    //intervals = {{9, 5},{4, 9},{1, 3},{5, 10},{5, 20},{3, 9}};
    //intervals = {{1,3},{2,6},{8,10},{15,18}};
    //intervals = {{1,4},{4,5}};
    intervals = {{1,4}};
    newInterval = {2,3};
    //intervals is NULL
    //newInterval = {4,6};
    //intervals = {{2,3},{4,5},{6,7},{8,9},{10,12}};
    //newInterval = {4,6};
    //intervals = {{1,3},{6,9}};
    //newInterval = {2,5};
    //intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    //newInterval = {4,8};
    vector<vector<int>> vans = sol->insert(intervals, newInterval);
    sol->dump(vans);
    
    free(sol);
}
#endif
