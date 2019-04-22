#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;

class Solution 
{
public:
    double myPow(double x, int n)
    {
        //-100.0 < x < 100.0
        //n is a 32-bit signed integer, within the range [INT_MIN, INT_MAX]
        if (n == 0) return 1;
        if (n == 1) return x;
        if (x == 0) return 0;
        
        double ans = 1;
        long ln = labs(n);
        
        while (ln)
        {
            double tmp = x;
            long lcnt = 1;
            while ((lcnt<<=1) < ln)
            {
                tmp *= tmp;
                //lcnt <<= 1;
            }
            ln = ln - (lcnt>>1);
            ans = ans * tmp;
        }
        
        if (n < 0)
            ans = 1/ans;
        return ans;
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    cout<<sol->myPow(2.00000,20)<<endl;
    cout<<sol->myPow(2.00000,-2)<<endl;
    cout<<sol->myPow(2.10000,3)<<endl;
    cout<<sol->myPow(-100.0,3)<<endl;
    cout<<sol->myPow(-99.0,INT_MAX)<<endl;
    cout<<sol->myPow(-99.0,INT_MIN)<<endl;
    cout<<sol->myPow(99.0,INT_MAX)<<endl;
    cout<<sol->myPow(99.0,INT_MIN)<<endl;
    cout<<sol->myPow(2.000,INT_MAX)<<endl;
    cout<<sol->myPow(-2.000,INT_MAX)<<endl;
    cout<<sol->myPow(-2.000,INT_MIN)<<endl;
    cout<<sol->myPow(8,3)<<endl;
    cout<<sol->myPow(-1.8,5)<<endl;
    cout<<sol->myPow(-1.8,-5)<<endl;
    cout<<sol->myPow(2,0)<<endl;
    cout<<sol->myPow(2,1)<<endl;
    cout<<sol->myPow(0.000,99)<<endl;
    
    free(sol);
}
#endif