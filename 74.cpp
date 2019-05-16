#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
  class Solution 
  {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        
        int right = n-1;
        int left = 0;
        int middle = n>>1;
        while (left <= right)
        {
            if (matrix[middle][0] < target)
                left = middle+1;
            else if (matrix[middle][0] > target)
                right = middle-1;
            else
                return true;
            middle = left + ((right-left)>>1);
        }

        if (middle < 0) return false; //for the case "{{1}}, 0"
        
        int row = middle;
        right = m-1;
        left = 0;
        middle = m>>1;
        while (left <= right)
        {
            if (matrix[row][middle] < target)
                left = middle+1;
            else if (matrix[row][middle] > target)
                right = middle-1;
            else
                return true;
            middle = left + ((right-left)>>1);
        }

        return false;    
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    
    vector<vector<int>> matrix;

    matrix = {};
    assert(false == sol->searchMatrix(matrix, 16));

    matrix = {{}};
    assert(false == sol->searchMatrix(matrix, 16));

    matrix = {{1}};
    assert(false == sol->searchMatrix(matrix, 0));

    matrix = {{1}};
    assert(false == sol->searchMatrix(matrix, 16));

    matrix = {{1}};
    assert(true == sol->searchMatrix(matrix, 1));

    matrix = 
    {
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
    };
    assert(true == sol->searchMatrix(matrix, 16));
    assert(true == sol->searchMatrix(matrix, 3));
    assert(false == sol->searchMatrix(matrix, 13));

    matrix = 
    {
    {1,   3,  5,  7},
    };
    assert(false == sol->searchMatrix(matrix, 16));
    assert(true == sol->searchMatrix(matrix, 3));
    assert(false == sol->searchMatrix(matrix, 13));

    matrix = 
    {
    {1},
    {3},
    {5},
    {7}
    };
    assert(false == sol->searchMatrix(matrix, 16));
    assert(true == sol->searchMatrix(matrix, 3));
    assert(true == sol->searchMatrix(matrix, 1));
    assert(true == sol->searchMatrix(matrix, 5));
    assert(true == sol->searchMatrix(matrix, 7));
    assert(false == sol->searchMatrix(matrix, 13));

    free(sol);
}
#endif