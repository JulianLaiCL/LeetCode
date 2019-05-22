#include <iostream>
#include <vector>
//#include <string>
//#include <cassert>
#include <algorithm>
//#include <unordered_map>
//#include <climits>

using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if (k == 0) return {}; //invalid
        int len = nums.size();
        if (len == 0) return {}; //invalid
        if (k > len) return {}; //invalid
        vector<int> vans;//(len-k+1);
        int maxidx = k; //to be updated for the first iteration
        int shift = 0;
        int tmp = 0;
        
        while (shift < (len-k+1))
        {
            tmp = maxidx - shift;
            if (tmp >= 0 && tmp < k)
            {
                tmp = shift+k-1;
                if (nums[maxidx] < nums[tmp])
                    maxidx = tmp;
                //update array
                //cout<<nums[maxidx]<<" ";
                vans.push_back(nums[maxidx]);
            }
            else //find new max value
            {
                auto it = max_element(begin(nums)+shift, begin(nums)+shift+k); // c++11
                maxidx = it - begin(nums);
                //update array
                //cout<<nums[maxidx]<<" ";
                vans.push_back(nums[maxidx]);
            }
            ++shift;
        }
        return vans;
        
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    vector<int> nums, vans;
    int k = 0;
    
    nums = {1,3,-1,-3,5,3,6,7};
    k = 7;
    vans = sol->maxSlidingWindow(nums, k);
    
    for (int i = 0; i < vans.size(); ++i)
        cout<<vans[i]<<" ";
    cout<<endl;
    
    //cout<<"TEST PASS!"<<endl;
    
    free(sol);
}
#endif
