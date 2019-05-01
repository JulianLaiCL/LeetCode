#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        for (int i = 1; i < n; ++i)
            grid[i][0] = grid[i][0] + grid[i-1][0];
        for (int k = 1; k < m; ++k)
            grid[0][k] = grid[0][k] + grid[0][k-1];

        for (int i = 1; i < n; ++i)
        {
            for (int k = 1; k < m; ++k)
            {
                grid[i][k] = grid[i][k] + min(grid[i-1][k], grid[i][k-1]);        
            }
        }

        return grid[n-1][m-1];
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    vector<vector<int>> matrix;
    
    matrix = 
    {
        {1,3,1},
        {1,5,1},
        {4,2,1} 
    };
    assert(7 == sol->minPathSum(matrix));

    matrix = 
    {
        {1,1,1,1,1},
        {1,5,1,1,1},
        {4,2,6,7,1} 
    };
    assert(7 == sol->minPathSum(matrix));

    matrix = 
    {
        {7}
    };
    assert(7 == sol->minPathSum(matrix));

    matrix = 
    {
        {7,1}
    };
    assert(8 == sol->minPathSum(matrix));

    matrix = 
    {
        {7},
        {1}
    };
    assert(8 == sol->minPathSum(matrix));
    
    matrix = 
    {
        {}
    };
    assert(0 == sol->minPathSum(matrix));

    matrix = 
    {
        {1,1,1,1,1},
        {1,5,1,1,5},
        {4,2,1,7,1},
        {4,2,1,2,9}, 
        {4,2,7,7,1} 
    };
    assert(16 == sol->minPathSum(matrix));

    matrix = 
    {{3,8,6,0,5,9,9,6,3,4,0,5,7,3,9,3},
    {0,9,2,5,5,4,9,1,4,6,9,5,6,7,3,2},
    {8,2,2,3,3,3,1,6,9,1,1,6,6,2,1,9},
    {1,3,6,9,9,5,0,3,4,9,1,0,9,6,2,7},
    {8,6,2,2,1,3,0,0,7,2,7,5,4,8,4,8},
    {4,1,9,5,8,9,9,2,0,2,5,1,8,7,0,9},
    {6,2,1,7,8,1,8,5,5,7,0,2,5,7,2,1},
    {8,1,7,6,2,8,1,2,2,6,4,0,5,4,1,3},
    {9,2,1,7,6,1,4,3,8,6,5,5,3,9,7,3},
    {0,6,0,2,4,3,7,6,1,3,8,6,9,0,0,8},
    {4,3,7,2,4,3,6,4,0,3,9,5,3,6,9,3},
    {2,1,8,8,4,5,6,5,8,7,3,7,7,5,8,3},
    {0,7,6,6,1,2,0,3,5,0,8,0,8,7,4,3},
    {0,4,3,4,9,0,1,9,7,7,8,6,4,6,9,5},
    {6,5,1,9,9,2,2,7,4,2,7,2,2,3,7,2},
    {7,1,9,6,1,2,7,0,9,6,6,4,4,5,1,0},
    {3,4,9,2,8,3,1,2,6,9,7,0,2,4,2,0},
    {5,1,8,8,4,6,8,5,2,4,1,6,2,2,9,7}};
    assert(83 == sol->minPathSum(matrix));
    
    free(sol);
}
#endif
