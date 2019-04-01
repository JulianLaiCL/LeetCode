#if 0
#include <iostream>
#include <vector>

using namespace std;
#endif

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.length() == 0) return 0;
        if (haystack.length() == 0) return -1;
        
        for (i = 0; i < haystack.length(); ++i)
        {
            if (haystack[i] == needle[0] && (i + needle.length() <= haystack.length()))
            {
                for (k = 1; k < needle.length(); ++k)
                {
                    if (haystack[i+k] != needle[k]) break;
                }
                if (k == needle.length()) return i;
            }
        }
        
        return -1;
    }
private:
    int i = 0;
    int k = 0;
};

#if 0
int main()
{
	Solution sol;
	string s1 = "too good to be true";
	string s2 = ""; //"good";
	int ans = sol.strStr(s1,s2);
	cout<<"ans="<<ans<<endl;
    return 0;
}
#endif