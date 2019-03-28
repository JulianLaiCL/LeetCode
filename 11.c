#define MY_MIN(x,y) (x<y?x:y)
int maxArea(int* height, int heightSize) 
{
    if (heightSize < 2) return 0;
    if (height == NULL) return 0;
    //Given heightSize non-negative integers
    int iMaxSize = 0;
    int iSize = 0;
    for (int i = 0; i < heightSize-1; ++i)
    {
        for (int k = heightSize-1; k > i; --k)
        {
            iSize = MY_MIN(height[i], height[k]) * (k-i);
            if (iSize > iMaxSize)
                iMaxSize = iSize;
            if (height[k] > height[i])
                break;            
        }
    }
    
    return iMaxSize;
}