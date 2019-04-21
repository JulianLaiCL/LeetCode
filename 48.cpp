#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int dim = matrix.size();
        for (int i = 0; i < dim/2; ++i)
        {
            for (int k = i; k < dim-1-i; ++k)
            {
                int pos1 = dim-1-i;
                int pos2 = dim-1-k;
                int tmp = matrix[k][pos1];
                
                matrix[k][pos1] = matrix[i][k];
                matrix[i][k] = matrix[pos2][i];
                matrix[pos2][i] = matrix[pos1][pos2];
                matrix[pos1][pos2] = tmp;
            }
        }
    }
    void dump(vector<vector<int>>& matrix)
    {
        int dim = matrix.size();
        for (int i = 0; i < dim; ++i)
        {
            for (int k = 0; k < dim; ++k)
                cout<<matrix[i][k]<<" ";
            cout<<endl;
        }
    }
};

#if 1
int main()
{
    Solution* sol = new Solution();
    vector<vector<int>> matrix;
    
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol->dump(matrix);
    sol->rotate(matrix);
    sol->dump(matrix);
    
    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    sol->dump(matrix);
    sol->rotate(matrix);
    sol->dump(matrix);
    
    matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    sol->dump(matrix);
    sol->rotate(matrix);
    sol->dump(matrix);
    
    free(sol);
}
#endif




