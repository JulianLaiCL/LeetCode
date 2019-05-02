#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int len = digits.size();
        if (len == 0) return {};

        int carry = 0;
        digits[len-1]+=1;
        for (int i = len-1; i >=0; --i)
        {
            digits[i] = digits[i]+carry;
            if (digits[i] >= 10)
            {
                digits[i] -= 10;
                carry = 1;
            }
            else
                carry = 0;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        //vector<int> vans(len+carry);
        //vans[0] = 1;
        //for (int i = 0; i < len; ++i)
        //{
        //    vans[i+carry] = digits[i];
        //}
        
        //for (int i = 0; i < vans.size(); ++i)
        //    cout<<vans[i]<<" ";
        //cout<<endl;

        //return vans;
        return digits;
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();

    vector<int> digits;
    vector<int> vans;
    
    digits = {1,2,3,4,5};
    vans = {1,2,3,4,6};
    assert(vans == sol->plusOne(digits));
    digits = {9,9,9};
    vans = {1,0,0,0};
    assert(vans == sol->plusOne(digits));
    digits = {};
    vans = {};
    assert(vans == sol->plusOne(digits));
    digits = {1};
    vans = {2};
    assert(vans == sol->plusOne(digits));
    digits = {8,8,1,7,0,9,9,9,9,9};
    vans = {8,8,1,7,1,0,0,0,0,0};
    assert(vans == sol->plusOne(digits));
    digits = {0};
    vans = {1};
    assert(vans == sol->plusOne(digits));

    free(sol);
}
#endif
