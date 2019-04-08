#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        if (board.size() != dimension) return false;
        for (int i = 0; i < dimension; ++i)
        {
            if (board[i].size() != dimension) return false;
        }

        vector<int> check(dimension,0);
        //rule 3
        for (int i = 0; i < dimension; i+=subdimension)
        {
            for (int k = 0; k < dimension; k+=subdimension)
            {
                std::fill(check.begin(),check.end(),0);
                for (int m = i; m < i+3; ++m)
                {
                    for (int n = k; n < k+3; ++n)
                    {
                        if (board[m][n] == '.') continue;
                        if (board[m][n] > '9' || board[m][n] < '1') continue;
                        if (check[board[m][n] - '1'] != 0) return false;
                        check[board[m][n] - '1'] = 1;
                    }
                }
            }
        }

        //rule 1
        for (int i = 0; i < dimension; ++i)
        {
            std::fill(check.begin(),check.end(),0);
            for (int k = 0; k < dimension; ++k)
            {
                if (board[i][k] == '.') continue;
                if (check[board[i][k] - '1'] != 0) return false;
                check[board[i][k] - '1'] = 1;
            }
        }
        //rule 2
        for (int i = 0; i < dimension; ++i)
        {
            std::fill(check.begin(),check.end(),0);
            for (int k = 0; k < dimension; ++k)
            {
                if (board[k][i] == '.') continue;
                if (check[board[k][i] - '1'] != 0) return false;
                check[board[k][i] - '1'] = 1;
            }
        }
        return true;
    }
private:
    const int dimension = 9;
    const int subdimension = 3;
};

#if 0
int main()
{
    Solution sol;
    vector<vector<char>> board = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<"ans = "<<sol.isValidSudoku(board)<<endl;
    assert(1==sol.isValidSudoku(board));
    
    board = 
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<"ans = "<<sol.isValidSudoku(board)<<endl;
    assert(0==sol.isValidSudoku(board));

    return 0;
}
#endif