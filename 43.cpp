#include <iostream>
#include <cassert>
#include <string>
//#include <algorithm>
#include <vector>

using namespace std;

class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0 || len2 == 0) return "";
        if (len1 == 1 && num1[0] == '0') return "0";
        if (len2 == 1 && num2[0] == '0') return "0";
        
        vector<int> vans(len1+len2);
        string sans;
        int leadzero = 1;
        for (int i = len1-1; i >= 0; --i)
        {
            int pos = len1-1-i;
            int tmp = 0;
            for (int k = len2-1; k >= 0; --k)
            {
                tmp = (num2[k]-'0') * (num1[i]-'0') + vans[pos];
                vans[pos+1] += tmp/10;
                vans[pos++] = tmp%10;
            }
        }

        for (int i = vans.size()-1; i >= 0; --i)
        {
            //skip leading 0
            if (vans[i] == 0 && leadzero == 1 && i >= 1)
                continue;
            leadzero = 0;
            sans = sans + to_string(vans[i]);
        }
        return sans;    
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    assert(sol->multiply("123", "456").compare("56088") == 0);
    assert(sol->multiply("2", "3").compare("6") == 0);
    assert(sol->multiply("8817067", "926338").compare("8167584210646") == 0);
    assert(sol->multiply("8817067", "0").compare("0") == 0);
    assert(sol->multiply("0", "0").compare("0") == 0);
    assert(sol->multiply("0", "9988776").compare("0") == 0);
    assert(sol->multiply("1234567890", "998877665544332211").compare("1233182291919191919193304790") == 0);
    assert(sol->multiply("10000000000", "1000000000000000000000000000000").compare("10000000000000000000000000000000000000000") == 0);
    assert(sol->multiply("10000000000000000000000000000000000000000000000000000000000000000000000", "10000000000").compare("100000000000000000000000000000000000000000000000000000000000000000000000000000000") == 0);
    free(sol);
}
#endif