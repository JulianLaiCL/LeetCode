#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
    int totalNQueens(int n) 
	{
        vector<vector<string>> vmatrix = solveNQueens(n);
		return vmatrix.size();
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vmatrix.clear();
        if (n <= 0) return vmatrix;
        if (n == 1) return {{"Q"}};

        dim = n;
        string str(n, '.');
        vector<string> matrix(n, str);
        //vmatrix.resize(n, vector<string>(n, "."));
        //dump(matrix);
        recplace(matrix, 0, 0);
        return vmatrix;
    }
    void dump(vector<string>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            cout<<matrix[i]<<endl;
        cout<<"=========="<<endl;
    }
private:
    vector<vector<string>> vmatrix;
    int dim = 0;
    bool isvalid(vector<string>& matrix, int x, int y)
    {
       for (int i = x-1; i >= 0; --i)
           if (matrix[i][y] == 'Q') return false;
       //for (int i = x+1; i < dim; ++i)
       //    if (matrix[i][y] == 'Q') return false;
       //for (int i = y-1; i >= 0; --i)
       //    if (matrix[x][i] == 'Q') return false;
       //for (int i = y+1; i < dim; ++i)
       //    if (matrix[x][i] == 'Q') return false;
       for (int i = x-1, k = y-1; i >= 0 && k >= 0; --i, --k)
           if (matrix[i][k] == 'Q') return false;
       //for (int i = x+1, k = y+1; i < dim && k < dim; ++i, ++k)
       //    if (matrix[i][k] == 'Q') return false;
       //for (int i = x+1, k = y-1; i < dim && k >= 0; ++i, --k)
       //    if (matrix[i][k] == 'Q') return false;
       for (int i = x-1, k = y+1; i >= 0 && k < dim; --i, ++k)
           if (matrix[i][k] == 'Q') return false;
       return true;
    }
    void recplace(vector<string>& matrix, int x, int y)
    {
           for (int k = y; k < dim; ++k)
           {
               //check valid first
               if (isvalid(matrix, x, k) == true)
               {
                   matrix[x][k] = 'Q';
                   if (x == dim-1)
                   {
                       //dump(matrix);
                       vmatrix.push_back(matrix);
                       matrix[x][k] = '.';
                       return;
                   }
                   else
                       recplace(matrix, x+1, 0); //move to next row
                   matrix[x][k] = '.';
               }
           }
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    vector<vector<string>> vmatrix;
	assert(0 == sol->totalNQueens(0));
	assert(1 == sol->totalNQueens(1));
	assert(0 == sol->totalNQueens(2));
	assert(0 == sol->totalNQueens(3));
	assert(2 == sol->totalNQueens(4));
	assert(92 == sol->totalNQueens(8));
    //sol->solveNQueens(0);
    //sol->solveNQueens(1);
    //sol->solveNQueens(2);
    //sol->solveNQueens(3);
    //sol->solveNQueens(4);
    //sol->solveNQueens(8);
    free(sol);
}
#endif