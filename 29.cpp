#if 0
#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;
#endif

class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        if (divisor == 0) return 0; //undefined
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if ((dividend == INT_MIN) && (divisor == -1)) return INT_MAX; //overflow
        if (labs(dividend) < labs(divisor)) return 0;

        ldividend = dividend;
        ldivisor = divisor;
        if (ldividend < 0)
        {
            neg = !neg;
            ldividend = 0 - ldividend;
        }
        if (ldivisor < 0)
        {
            neg = !neg;
            ldivisor = 0 - ldivisor;
        }
        while (ldividend >= ldivisor)
        {
            cnt = 1;
            while ((ldividend - (ldivisor<<1)) >= 0)
            {
                cnt <<= 1;
                ldivisor <<= 1;
            }
            ret += cnt;
            ldividend -= ldivisor;
            ldivisor = labs(divisor);
        }
        if (neg) ret = 0 - ret;
        return ret;
    }
private:
    long ldividend = 0;
    long ldivisor = 0;
    int neg = 0;
    int cnt = 1;
    int ret = 0;
};

#if 0
int main()
{
	Solution sol;
	int ans = sol.divide(9,3);
	cout<<"ans="<<ans<<endl;
	cout<<INT_MIN<<" "<<INT_MAX<<endl;
	return 0;
}
#endif