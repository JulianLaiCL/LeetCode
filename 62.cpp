#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        if (m <= 0 || n <= 0) return 0; //invalid
        if (m == 1 || n == 1) return 1;
        
        vector<vector<int>> matrix(n, vector<int>(m,1));
        for (int i = 1; i < n; ++i)
        {
            for (int k = 1; k < m; ++k)
            {
                matrix[i][k] = matrix[i-1][k] + matrix[i][k-1];
            }
        }
        return matrix[n-1][m-1];
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    assert(3 == sol->uniquePaths(3, 2));
    assert(28 == sol->uniquePaths(7, 3));
    assert(0 == sol->uniquePaths(7, 0));
    assert(0 == sol->uniquePaths(0, 0));
    assert(163011640 == sol->uniquePaths(30, 10));
    assert(4421275 == sol->uniquePaths(100, 5));
    free(sol);
}
#endif
