#include <iostream>
#include <cassert>

using namespace std;

class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        if (s.length() == 0) return 0;
        for (int i = s.length()-1; i >= 0; --i)
        {
            //find first non-space
            if (s[i] != ' ')
            {
                //find the lenght of the first encounter word
                for (int k = i; k >= 0; --k)
                {
                    if (s[k] == ' ')
                        return (i-k);
                    if (k == 0)
                        return (i-k+1);
                }
            }
        }
        return 0;
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    assert(5 == sol->lengthOfLastWord("hello world"));
    assert(5 == sol->lengthOfLastWord("hello      "));
    assert(0 == sol->lengthOfLastWord("      "));
    assert(1 == sol->lengthOfLastWord(" a b c d   "));
    assert(0 == sol->lengthOfLastWord(""));
    assert(0 == sol->lengthOfLastWord(" "));
    assert(4 == sol->lengthOfLastWord(" abcde abcd "));

    free(sol);
}
#endif
