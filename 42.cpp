#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int ians = 0; //return value
        int curMaxL = 0; //start point of a cave
        int caveMaxR = 0; //maximum height after a cave
        int locMaxR = 0; //location of maximum height after a cave
        int cave = 0; //is there a possible cave?
        int tmp = 0; //estimated water volumn
        for (int i = 0; i < height.size(); ++i)
        {
            if (height[i] >= curMaxL)
            {
                curMaxL = height[i];
                //find the right height that can make a hole to store water
                int k = i+1;
                for (; k < height.size(); ++k)
                {
                    if (tmp > 0 && k > i+1 && height[k] > height[k-1])
                    {
                        cave = 1;
                        if (height[k] > caveMaxR)
                        {
                            caveMaxR = height[k];
                            locMaxR = k;
                        }
                    }
                    if (height[k] < curMaxL)
                        tmp += (curMaxL-height[k]);
                    else
                    {
                        //hit a wall which is higher than curMaxL
                        i = k - 1;
                        break;
                    }
                }
                
                if (k == height.size())
                {
                    if (caveMaxR) //set current left hight to maxR and re-scan
                    {
                        int m = i;
                        for (; m < locMaxR; ++m)
                            if (height[m] >= caveMaxR)
                            {
                                height[m] = caveMaxR;
                                i = m - 1;
                            }    
                    }
                    curMaxL = 0;
                }
                else
                {
                    ians += tmp;
                }
                tmp = 0;
                caveMaxR = 0;
                locMaxR = 0;
                cave = 0;
            }
        }
        //cout<<"ians="<<ians<<endl;
        return ians;
    }
};

#if 0
int main()
{
    vector<int> height;
    Solution* sol = new Solution();

    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    assert(6==sol->trap(height));
    height = {0,1,1,9,1,0,1,3,2,1,2,1};
    assert(8==sol->trap(height));
    height = {9,8,7,6,5,4,3,2,1,2,3,2,1,1,2};
    assert(6==sol->trap(height));
    height = {2,1,1,2,3,2,1,2,3,4,5,6,7,8,9};
    assert(6==sol->trap(height));
    height = {9,8,9,8,7,8,7,6,5,6,100,200,0,1};
    assert(18==sol->trap(height));
    height = {5,5,5,5,5,6,6,6,6,7,7,7,7,7,5,100};
    assert(2==sol->trap(height));
    height = {9,8,7,6,5,4,3,2,1,0,1};
    assert(1==sol->trap(height));
    height = {1000,0,100,0,50,0,30};
    assert(180==sol->trap(height));
    height = {1000,0,100,0,50,0,1000};
    assert(4850==sol->trap(height));

    return 0;
}
#endif