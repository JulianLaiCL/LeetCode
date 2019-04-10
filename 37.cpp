#include <iostream>
#include <vector>
//#include <cassert>

using namespace std;

class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        if (recSolveSudoku(board) == false)
            cout<<"Failed to find a solution!"<<endl;
    }

    void dumpMatrix(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int k = 0; k < 9; ++k)
            {
                cout<<board[i][k]<<" ";
            }
            cout<<endl;
        }
    }
private:
    const int dimension = 9;
    const int subdimension = 3;

    bool isValidFullSudoku(vector<vector<char>>& board) 
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
                        if (board[m][n] == '.') return false; //continue;
                        //if (board[m][n] > '9' || board[m][n] < '1') continue;
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
                if (board[i][k] == '.') return false; //continue;
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
                if (board[k][i] == '.') false; //continue;
                if (check[board[k][i] - '1'] != 0) return false;
                check[board[k][i] - '1'] = 1;
            }
        }

        //dumpMatrix(board);
        return true;
    }

    bool recSolveSudoku(vector<vector<char>>& board) 
    {
        //error handling
        if (board.size() != dimension) return false;
        for (int i = 0; i < dimension; ++i)
        {
            if (board[i].size() != dimension) return false;
        }

        vector<int> vcheck(dimension,0);
        int weight = 0;
        int maxweight = -1;
        int ans = 0;
        vector<vector<int>> vguess;
        for (int i = 0; i < dimension; ++i)
        {
            for (int k = 0; k < dimension; ++k)
            {
                weight = 0;
                std::fill(vcheck.begin(),vcheck.end(),0);
                if (board[i][k] == '.')
                {
                    //search horizontal
                    for (int m = 0; m < dimension; ++m)
                        if (board[m][k] != '.') vcheck[board[m][k] - '1'] = 1;
                    //search vertical
                    for (int m = 0; m < dimension; ++m)
                        if (board[i][m] != '.') vcheck[board[i][m] - '1'] = 1;
                    //search 3x3 matrix
                    for (int m = (i/subdimension)*subdimension; m < ((i/subdimension)*subdimension)+subdimension; ++m)
                        for (int n = (k/subdimension)*subdimension; n < ((k/subdimension)*subdimension)+subdimension; ++n)
                            if (board[m][n] != '.') vcheck[board[m][n] - '1'] = 1;
                            
                    for (int m = 0; m < dimension; ++m)
                    {
                        weight += vcheck[m];
                        if (vcheck[m] == 0) ans = m;
                    }

                    if (weight == (dimension-1))
                    {
                        //cout<<"FOUND coordination = "<<i<<" and "<<k<<" is "<<ans+1<<endl; 
                        board[i][k] = '1' + ans;
                        i = -1; //Not Good
                        maxweight = -1;
                        for(int m = 0; m < vguess.size(); ++m)
                            vguess[m].clear();
                        vguess.clear();
                        break;
                    }
                    else if (weight >= maxweight)
                    {
                        if (weight > maxweight)
                        {
                            for(int m = 0; m < vguess.size(); ++m)
                                vguess[m].clear();
                            vguess.clear();
                        }
                        maxweight = weight;
                        //cout<<"maxweight = "<<maxweight<<",i,k="<<i<<" "<<k<<endl;

                        vguess.push_back(vector<int>());
                        vguess[vguess.size()-1].push_back(i);
                        vguess[vguess.size()-1].push_back(k);

                        for (int m = 0; m < dimension; ++m)
                            if (vcheck[m] == 0)
                                vguess[vguess.size()-1].push_back(m+1);
                    }
                }
            }
        }

        for (int i = 0; i < vguess.size(); ++i)
        {
            for (int k = 2; k < vguess[i].size(); ++k)
            {
                //make a guess
                vector<vector<char>> vtmp;
                for (int m = 0; m < dimension; ++m)
                    vtmp.push_back(board[m]);
                
                vtmp[vguess[i][0]][vguess[i][1]] = vguess[i][k] + '0';
                //dumpMatrix(vtmp);

                if (recSolveSudoku(vtmp) == true)
                {
                    for (int m = 0; m < dimension; ++m)
                        for (int n = 0; n < dimension; ++n)
                            board[m][n] = vtmp[m][n];
                    return true;            
                }
            }
        }

        return isValidFullSudoku(board);
    }
};

#if 0
int main()
{
    Solution sol;
    vector<vector<char>> board = 
    {
#if 1
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
#elif 0
        {'8','.','.','.','.','.','.','.','.'},
        {'.','.','3','6','.','.','.','.','.'},
        {'.','7','.','.','9','.','2','.','.'},
        {'.','5','.','.','.','7','.','.','.'},
        {'.','.','.','.','4','5','7','.','.'},
        {'.','.','.','1','.','.','.','3','.'},
        {'.','.','1','.','.','.','.','6','8'},
        {'.','.','8','5','.','.','.','1','.'},
        {'.','9','.','.','.','.','4','.','.'}
#elif 1
        {'8','1','2','7','.','.','.','.','.'},
        {'.','.','3','6','.','.','.','.','.'},
        {'.','7','.','.','9','.','2','.','.'},
        {'.','5','.','.','.','7','.','.','.'},
        {'.','.','.','.','4','5','7','.','.'},
        {'.','.','.','1','.','.','.','3','.'},
        {'.','.','1','.','.','.','.','6','8'},
        {'.','.','8','5','.','.','.','1','.'},
        {'7','9','6','3','.','.','4','5','2'}
#endif
    };
    
    sol.solveSudoku(board);
    sol.dumpMatrix(board);
    
    return 0;
}
#endif