#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
    
class Solution 
{
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) 
    {
        //1 <= K <= A.length <= 500
        //0 <= A[i] <= 10^6
        int len = A.size();
        if (len == 0) return 0;
        
        vector<int> dp(len);
        dp[0] = A[0];
        int curmax = A[0];

        for (int i = 1; i < K; ++i)
        {
            curmax = max(curmax, A[i]);
            dp[i] = curmax*(i+1);
        }

        for (int i = K; i < len; ++i)
        {
            curmax = A[i];
            for (int m = i; i-m < K; --m)
            {
                curmax = max(curmax, A[m]);
                dp[i] = max(dp[i], curmax*(i-m+1) + dp[m-1]);
            }
        }
        return dp[len-1];
    }
};  

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    
    vector<int> A;
    int K = 0;
    
    A = {1,4,1,5,7,3,6,1,9,9,3};
    K = 4;
    assert(83 == sol->maxSumAfterPartitioning(A, K));
    A= {1,15,7,9,2,5,10};
    K = 3;
    assert(84 == sol->maxSumAfterPartitioning(A, K));
    cout<<"PASS!"<<endl;
    free(sol);
}
#endif
    
