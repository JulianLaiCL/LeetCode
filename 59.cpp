#include <iostream>
//#include <cassert>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        if (n <= 0) return vector<vector<int>>();
        int total = (n*n) + 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int count = 1;
        int left = 0, right = 1, up = 0, down = 0;
        int leftbound = -1, rightbound = n, upbound = -1, downbound = n;
        int posx = 0, posy = 0;
        while (count < total)
        {
            while (right && posy < rightbound)
            {
                matrix[posx][posy] = count++;
                if (++posy >= rightbound)
                {
                    right = 0;
                    down = 1;
                    --posy;
                    ++posx;
                    --rightbound;
                    ++upbound;
                    break;
                }
            }
            while (down && posx < downbound)
            {
                matrix[posx][posy] = count++;
                if (++posx >= downbound)
                {
                    down = 0;
                    left = 1;
                    --posx;
                    --posy;
                    --downbound;
                    break;
                }
            }
            while (left && posy > leftbound)
            {
                matrix[posx][posy] = count++;
                if (--posy <= leftbound)
                {
                    left = 0;
                    up = 1;
                    ++posy;
                    --posx;
                    ++leftbound;
                    break;
                }
            }
            while (up && posx > upbound)
            {
                matrix[posx][posy] = count++;
                if (--posx <= upbound)
                {
                    up = 0;
                    right = 1;
                    ++posx;
                    ++posy;
                    //++upbound;
                    break;
                }
            }
        }
        return matrix;
    }
    void dump(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int k = 0; k < matrix[i].size(); ++k)
                cout<<matrix[i][k]<<" ";
            cout<<endl;
        }
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    vector<vector<int>> matrix; 
    matrix = sol->generateMatrix(6);
    sol->dump(matrix);
    
    free(sol);
}
#endif
