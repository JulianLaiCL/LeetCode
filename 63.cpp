#include <iostream>
#include <cassert>
#include <vector>
#include <iomanip>
//#include <climits>

using namespace std;

class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;
        //if (obstacleGrid[n-1][m-1] == 1) return 0;

        vector<vector<long>> vans(n, vector<long>(m)); //one of the test cases is unreasonable that results in integer overflow

        int encounter = 0;
        for (int i = 0; i < n; ++i)
        {
            if (encounter == 0 && obstacleGrid[i][0] != 1) 
                vans[i][0] = 1;
            else 
            {
                vans[i][0] = 0;
                encounter = 1;
            }
        }

        encounter = 0;
        for (int k = 0; k < m; ++k)
        {
            if (encounter == 0 && obstacleGrid[0][k] != 1) 
                vans[0][k] = 1;
            else 
            {
                vans[0][k] = 0;
                encounter = 1;
            }
        }
        
        for (int i = 1; i < n; ++i)
        {
            for (int k = 1; k < m; ++k)
            {
                if (obstacleGrid[i][k] == 1) 
                {
                    vans[i][k] = 0; //obstacle
                    continue;
                }
                else
                {
                    vans[i][k] = vans[i-1][k] + vans[i][k-1];
                }
            }
        }
        
        //dump(vans);
        return vans[n-1][m-1];
    }
    void dump(vector<vector<long>>& matrix, int width = 0)
    {
        cout<<"dump matrix:"<<endl;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int k = 0; k < matrix[i].size(); ++k)
            {
                cout<<setw(width)<<matrix[i][k]<<" ";
            }
            cout<<endl;
        }
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    vector<vector<int>> obstacleGrid;

    obstacleGrid = 
    {{0}};
    assert(1 == sol->uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = 
    {{0,1}};
    assert(0 == sol->uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = 
    {{1,0}}; //??
    assert(0 == sol->uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = 
    {{0,0,0},
     {0,1,0},
     {0,0,0}};
    assert(2 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);
    
    obstacleGrid = 
    {{0,0,0,0},
     {0,1,0,1},
     {0,0,0,0}};
    assert(2 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);
    
    obstacleGrid = 
    {{0,0,0,0},
     {0,1,0,1},
     {0,0,1,0}};
    assert(0 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);

    obstacleGrid = 
    {{0,0,0,1},
     {0,1,0,0},
     {0,0,0,0}};
    assert(3 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);

    obstacleGrid = 
    {{0,0,1,0,0}};
    assert(0 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);

    obstacleGrid = 
    {{0,0,0,0,0}};
    assert(1 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);

    obstacleGrid = 
    {{0},
     {0},    
     {0},    
     {0}
    };
    assert(1 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);

    obstacleGrid = 
    {{0},
     {1},    
     {0},    
     {0}
    };
    assert(0 == sol->uniquePathsWithObstacles(obstacleGrid));
    //sol->dump(obstacleGrid);
    
    obstacleGrid = 
    {{0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
    {0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},
    {1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},
    {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},
    {0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},
    {1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}};
    sol->uniquePathsWithObstacles(obstacleGrid);
    //sol->dump(obstacleGrid, 10);
    
    free(sol);
}
#endif
