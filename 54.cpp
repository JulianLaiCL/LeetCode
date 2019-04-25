#include <iostream>
//#include <cassert>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};
        int total = m*n;
        
        vector<int> ans(total);
        
        int count = 0;
        int left = 0, right = 1, up = 0, down = 0;
        int leftbound = -1, rightbound = n, upbound = -1, downbound = m;
        int posx = 0, posy = 0;
        while (count < total)
        {
            while (right && posy < rightbound)
            {
                ans[count] = matrix[posx][posy];
                ++count;   
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
                ans[count] = matrix[posx][posy];
                ++count;   
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
                ans[count] = matrix[posx][posy];
                ++count;   
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
                ans[count] = matrix[posx][posy];
                ++count;   
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
        return ans; 
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    vector<vector<int>> matrix = 
    {
#if 1
        {1},
        {5},
        {9}
#elif 0
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
#elif 0
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
#elif 0
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
#elif 0
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
#elif 0
        {1, 2, 3},
#elif 0
        {1},
#endif
    };
    vector<int> ans = sol->spiralOrder(matrix);
    for (int i = 0; i < ans.size(); ++i)
        cout<<ans[i]<<",";
    cout<<endl;

    free(sol);
}
#endif
