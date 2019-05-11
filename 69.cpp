#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;

class Solution 
{
public:
    int mySqrt(int x) 
    {
        //x is guaranteed to be a non-negative integer.
        if (x == 0) return 0;
        //if (x == 1) return 1;
        int left = 1;
        int right = x;
        int mid = 0;
        
        while ((left+1) < right)
        {
            //mid = (left + right) >> 1; //overflow
            mid = left + ((right - left) >> 1);
            //if (mid*mid > x) //overflow
            if (mid > (x/mid))
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return left;
    }
};

#if 0//MYDEBUG
int main()
{
    Solution* sol = new Solution();
    int x = 0;
    x = 1024;
    assert((int)sqrt(x) == sol->mySqrt(x));
    x = 10;
    assert((int)sqrt(x) == sol->mySqrt(x));
    x = 8;
    assert((int)sqrt(x) == sol->mySqrt(x));
    x = 24689;
    assert((int)sqrt(x) == sol->mySqrt(x));
    x = 1;
    assert((int)sqrt(x) == sol->mySqrt(x));
    x = 0;
    assert((int)sqrt(x) == sol->mySqrt(x));
    x = INT_MAX;
    assert((int)sqrt(x) == sol->mySqrt(x));
    x = 8817067;
    assert((int)sqrt(x) == sol->mySqrt(x));

    cout<<"PASS!"<<endl;
    free(sol);
}
#endif
