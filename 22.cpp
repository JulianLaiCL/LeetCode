#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n <= 0) return vector<string>();
        dfs("", n, n);
        return vstr;
    }
private:
    vector<string> vstr;
    void dfs(string s, int left, int right)
    {
        if ((left == 0) && (right == 0))
        {
            vstr.push_back(s);
            return ;
        }       
        
        if ((left > 0) && (left-1 <= right))
            dfs(s+"(", left-1, right);
        
        if ((right > 0) && (right-1 >= left))
            dfs(s+")", left, right-1);
    }
};

#if 0
int main()
{
    Solution sol;
    vector<string> vstr = sol.generateParenthesis(0);
    for (int n = 0; n < vstr.size(); ++n)
        cout<<vstr[n]<<endl;

    return 0;
}
#endif