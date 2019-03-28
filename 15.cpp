#if 0
#include <iostream>
#include <vector>

using namespace std;
#endif

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.size() < 3)
        {
            //error handing here
            return vecarr;
        }
        //bubble sort
        int tmp = 0;
        for (int i = 0; i < nums.size()-1; ++i)
        {
            for (int k = i; k < nums.size(); ++k)
            if (nums[i] > nums[k])
            {
                tmp = nums[k];
                nums[k] = nums[i];
                nums[i] = tmp;                
            }
        }
        //for (int i = 0; i < nums.size(); ++i)
        //    cout<<nums[i]<<" ";
        //cout<<endl;
        
        for (int i = 0; i < nums.size()-2; ++i)
        {
            if (nums[i] > 0) break;
            if ((i > 0) && (nums[i] == nums[i-1])) continue;
            left = i + 1;
            right = nums.size()-1;
            while (left < right)
            {
                if (nums[i] + nums[left] > 0) break;
                if ((left > i+1) && (nums[left] == nums[left-1]))
                {
                    ++left;
                    continue;
                }
                if ((right < nums.size()-1) && (nums[right] == nums[right+1])) 
                {
                    --right;
                    continue;
                }
                
                tmp = nums[i] + nums[left] + nums[right];
                if (tmp > 0)
                {
                    --right;
                    continue;
                }
                if (tmp < 0)
                {
                    ++left;
                    continue;
                }

                vecarr.push_back(vector<int>(3));
                tmp = vecarr.size()-1;
                vecarr[tmp][0] = nums[i];
                vecarr[tmp][1] = nums[left];
                vecarr[tmp][2] = nums[right];
                ++left;
                --right;
            }
        }
        return vecarr;
    }
private:
    vector<vector<int>> vecarr;
    int left = 0;
    int right = 0;
};
#if 0
int main()
{
    vector<int> myvec = 
    //{-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    {-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3}; 
    //{-3,1,-5,-1,0,-1,3,-4,1,2,-1,-1,-4,-4};
    //{-1, 0, 1, 2, -1, -4, 0, 0, -1, -1, 2, 2, 1, 1};

    Solution sol;
    vector<vector<int>> vecarr = sol.threeSum(myvec);
    cout<<endl<<"SIZE = "<<vecarr.size()<<endl;
    for (int i = 0; i < vecarr.size(); ++i)
    {
        for (int k = 0; k < vecarr[i].size(); ++k)
            cout<<vecarr[i][k]<<" ";
        cout<<endl;
    }

    return 0;
}
#endif