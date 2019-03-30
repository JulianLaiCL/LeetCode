#if 0
#include <iostream>
#include <vector>

using namespace std;
#endif

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        //nums is a sorted array
        if (nums.size() == 0) return 0;
        
        auto it = nums.begin();
        val = *it;
        ++it;
        while (it != nums.end())
        {
            if (*it != val)
            {
                val = *it;
                ++it;
            }
            else
            {
                it = nums.erase(it);
            }
        }
        return nums.size();
    }
private:
    int val = 0;
};

#if 0
int main()
{
	vector<int> nums = {1,1,1,1,1,2,2,2,2,2,2,2,3,4,5,6,6,7,7,7};
	Solution sol;
	int ans = sol.removeDuplicates(nums);
	cout<<"len="<<ans<<endl;

    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
#endif