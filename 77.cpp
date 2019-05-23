#include <iostream>
#include <vector>
#include <cassert>
//#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        if (n == 0 || k == 0) return {}; //invalid; return empty vector
        if (n < k) return {}; //invalid
        vector<int> v(k);
        gn = n;
        gk = k;
        dfs(k, 1, v);
        return vans;
    }
private:
    vector<vector<int>> vans;
    int gn = 0;
    int gk = 0;
    void dfs(int k, int start, vector<int>& v)
    {
        if (k == 0)
        {
            vans.push_back(v);
            return;
        }
        for (int i = start; i <= gn; ++i)
        {
            if (gn-i+1 < k) return;
            v[gk-k] = i;
            dfs(k-1, i+1, v);
        }
    }
};

#if 0 //MYDEBUG
int factorial(int n)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    int total = 1;
    for (int i = n; i > 1; --i)
        total*=i;
    return total;
}
int main()
{
    Solution* sol = new Solution();
    vector<vector<int>> vans;
    
    int n = 0, k = 0, total = 0;
    
    n = 4;
    k = 4;
    vans = sol->combine(n,k);
    
    if (n != 0 && k != 0 && n >= k)
    {
        total = factorial(n);
        total /= factorial(k);
        total /= factorial(n-k);
    }    
#if 1
    for (int i = 0; i < vans.size(); ++i)
    {
        //cout<<"idx "<<i<<endl;
        for (int k = 0; k < vans[i].size(); ++k)
            cout<<vans[i][k]<<" ";
        cout<<endl;
    }
#endif
    assert(total == vans.size());

    free(sol);
}
#endif
