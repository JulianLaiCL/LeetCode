#include <iostream>
#include <string>
#include <algorithm> //reverse()
#include <cassert>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b) 
    {
        //The input strings are both non-empty
        int lena = a.length();
        int lenb = b.length();
        string s;
        
        int carry = 0;
        int vala = 0, valb = 0;
		int tmp = 0;
        while (lena > 0 || lenb > 0)
        {
            --lena;
            --lenb;
            if (lena >= 0)
                vala = a[lena] - '0';
            else
                vala = 0;
            if (lenb >= 0)
                valb = b[lenb] - '0';
            else
                valb = 0;
            tmp = vala + valb + carry;
			if (tmp == 0)
			{
				s = s + "0";
				carry = 0;				
			}
			else if (tmp == 1)
			{
				s = s + "1";
				carry = 0;				
			}
			else if (tmp == 2)
			{
				s = s + "0";
				carry = 1;				
			}
			else //if (tmp == 3)
			{
				s = s + "1";
				carry = 1;				
			}
        }
        if (carry)
            s += '1';

        reverse(s.begin(), s.end());
        return s;
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();

    assert("100" == sol->addBinary("11", "1"));
    assert("10" == sol->addBinary("1", "1"));
    assert("10101" == sol->addBinary("1010", "1011"));
    assert("1011" == sol->addBinary("1010", "1"));
    assert("11100" == sol->addBinary("10101", "111"));
    cout<<"PASS!!"<<endl;;
    
    free(sol);
}
#endif
