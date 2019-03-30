#if 0
#include <iostream>
#include <vector>

using namespace std;
#endif

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if (nums.size() == 0) return 0;

        auto it = nums.begin();
        while (it != nums.end())
        {
            if (*it == val)
            {
                it = nums.erase(it);
            }
            else
            {
                ++it;
            }
        }
        return nums.size();//ans;
    }
};

#if 0
int main()
{
	vector<int> nums = {1,1,1,1,1,2,2,2,2,2,2,2,3,4,5,6,6,7,7,7,100,100};
	Solution sol;
	int ans = sol.removeElement(nums, 2);
	
	cout<<"len="<<ans<<endl;

    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
#endif