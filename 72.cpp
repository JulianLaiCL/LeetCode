#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int lw1 = word1.length();
        int lw2 = word2.length();
        
        vector<vector<int>> v(lw2+1, vector<int>(lw1+1));
        for (int i = 0; i <= lw1; ++i)
            v[0][i] = i;
        for (int i = 1; i <= lw2; ++i)
            v[i][0] = i;
        
        //replace : v[i][k] = v[i-1][k-1] + 1
        //deletion : v[i][k] = v[i][k-1] + 1
        //insertion : v[i][k] = v[i-1][k] + 1
        //do nothing : min(v[i-1][k-1], v[i-1][k]+1, v[i][k-1]+1)
        for (int i = 1; i <= lw2; ++i)
        {
            for (int k = 1; k <= lw1; ++k)
            {
                if (word1[k-1] != word2[i-1])
                    v[i][k] = min(min(v[i][k-1], v[i-1][k]), v[i-1][k-1]) + 1;
                else
                    v[i][k] = min(min(v[i][k-1]+1, v[i-1][k]+1), v[i-1][k-1]);
            }
        }
        return v[lw2][lw1];    
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    
    assert(3 == sol->minDistance("horse", "ros"));
    assert(5 == sol->minDistance("intention", "execution"));
    assert(9 == sol->minDistance("", "execution"));
    assert(9 == sol->minDistance("intention", ""));
    assert(3 == sol->minDistance("sunday", "saturday"));
    assert(2 == sol->minDistance("geek", "geesek"));
    assert(0 == sol->minDistance("", ""));
    assert(4 == sol->minDistance("kkooooo", "ooooomm"));
    assert(2 == sol->minDistance("zoolo", "zoo"));
    assert(10 == sol->minDistance("zoologicoarchaeologist", "zoogeologist"));
    cout<<"PASS!"<<endl;
    free(sol);
}
#endif
