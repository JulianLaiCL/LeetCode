#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        //Given n will be a positive integer.
#if 0
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        return climbStairs(n-1) + climbStairs(n-2);
#else
        vector<int> vans(n+1);
        vans[0] = 1;
        vans[1] = 1;
        for (int i = 2; i <= n; ++i)
            vans[i] = vans[i-1] + vans[i-2];    

        return vans[n];
#endif
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    
    assert(2 == sol->climbStairs(2));
    assert(3 == sol->climbStairs(3));
    //assert(0 == sol->climbStairs(0)); //invalid input
    assert(1 == sol->climbStairs(1));
    assert(1 == sol->climbStairs(1));
    assert(5 == sol->climbStairs(4));
    assert(8 == sol->climbStairs(5));
    assert(1134903170 == sol->climbStairs(44));

cout<<"sol="<<sol->climbStairs(44)<<endl;

    cout<<"PASS!"<<endl;
    free(sol);
}
#endif
