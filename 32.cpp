#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        if (s.length() == 0) return 0;
    
        int ret = 0;
        int tmplen = 0;
        stack<int> mystack;
        vector<myparenthesis> myvec(s.length());

        for (int i = 0; i < s.length(); ++i)
        {
            if (mystack.empty() && s[i] == ')')
            {
                myvec[i].rparen = 0;
                myvec[i].count = -1;
                continue;   
            }
            else if (s[i] == ')')
            {
                mystack.pop();
                myvec[i].rparen = 1;
                myvec[i].count = mystack.size();
            }
            else if (s[i] == '(')
            {
                mystack.push(1);
                myvec[i].rparen = 0;
                myvec[i].count = mystack.size();
            }
        }
#if 0
        for (int m = 0; m < myvec.size(); ++m)
        {
            cout<<myvec[m].count<<" ";
        }
        cout<<endl;
#endif        
        for (int k = myvec.size()-1; k >= 0; --k)
        {
            if (myvec[k].rparen == 1)
            {
                int len = 0;
                for (int m = k-1; m >= 0; --m)
                {
                    if (myvec[m].count == -1) break;
                    if (myvec[m].count < myvec[k].count) break;
                    if (myvec[m].count == (myvec[k].count+1) && myvec[m].rparen == 0)
                    {
                        len = k - m + 1;
                        ret = (len > ret) ? len : ret;
                    }
                }
                k = k - len + 1;
            }
        }
        return ret;
    }
private:
    struct myparenthesis
    {
        int count;
        int rparen;
    };
};

#if 0
int main()
{
	Solution sol;
	cout<<"maxlen = "<<sol.longestValidParentheses(")))((((()))))")<<endl;
	cout<<"maxlen = "<<sol.longestValidParentheses(")))()())(()()))(())(())")<<endl;
	cout<<"maxlen = "<<sol.longestValidParentheses("((((((()(((((()")<<endl;
	cout<<"maxlen = "<<sol.longestValidParentheses(")()())")<<endl;
	cout<<"maxlen = "<<sol.longestValidParentheses("(())()(()((")<<endl;
	
	return 0;
}
#endif