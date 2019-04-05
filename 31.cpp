#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.size() <= 1) return;
        //process from the lowest digit to highest digit
        for (int i = nums.size()-2; i >= 0; --i)
        {
            //find the closet larger number
            int swapidx = -1;
            //int clos
            for (int n = i+1; n < nums.size(); ++n)
            {
                if (nums[i] < nums[n])
                {
                    //cout<<"may swap idx "<<i<<" and "<<n<<endl;
                    swapidx = n;
                }
            }
            if (swapidx != -1)
            {
                //swap & sort lower digits
                int tmp = nums[i];
                nums[i] = nums[swapidx];
                nums[swapidx] = tmp;
                std::sort(nums.begin()+i+1, nums.end());
                break;
            }
            if (i == 0)
            {
                std::sort(nums.begin(), nums.end());
            }
        }
    }
};

#if 0
int main()
{
/*
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
*/
	vector<int> nums = {5, 6, 8, 9, 4, 3};
	//vector<int> nums = {1,2,3};
	//vector<int> nums = {3,2,1};
	//vector<int> nums = {1,1,5};
	//vector<int> nums = {1,5,2,4,5,6,4,3,2,9,7};
	//vector<int> nums = {9,8,7,6,5,2,4,3,1};
	//vector<int> nums = {9,8,7,6,5,4,3,2,1};
	Solution sol;
	sol.nextPermutation(nums);
	
	for (int i = 0; i <nums.size(); ++i)
	{
	    cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
#endif