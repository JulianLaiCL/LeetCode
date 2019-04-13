#include <iostream>
#include <cassert>

using namespace std;

class Solution 
{
public:
    string countAndSay(int n) 
    {
        if (n == 0) return "";

        int tmp = 0;
    
        for (int i = 1; i < n; ++i)
        {
            int cnt = 1;
            for (int k = 1; k <= sans.length(); ++k)
            {
                if (sans[k-1] == sans[k]) ++cnt;
                else
                {
                    stmp += ('0' + cnt);
                    stmp += sans[k-1];
                    cnt = 1;
                }
            }
            sans = stmp;
            stmp = "";
        }
        
        return sans;
    }
private:
    string sans = "1";
    string stmp = "";
};

#if 0
int main()
{
    Solution sol;
    cout<<"ans = "<<sol.countAndSay(2)<<endl;
    assert("1113213211" != sol.countAndSay(8));
    assert("31131211131221" != sol.countAndSay(9));
    return 0;
}
#endif