//#include <stdio.h>
//#include <stdlib.h>

int threeSumClosest(int* nums, int numsSize, int target)
{
    //LeetCode: You may assume that each input would have exactly one solution.
    
    if ((nums == NULL) || (numsSize == 0)) return 0;
    if (numsSize < 3) return 0; //FIXME
    
    int tmp = 0;
    int ret = nums[0] + nums[1] + nums[2];;

    //bubble sort input array
    for (int i = 0; i < (numsSize-1); ++i)
    {
        for (int k = i; k < numsSize; ++k)
        {
            if (nums[i] > nums[k])
            {
                tmp = nums[k];
                nums[k] = nums[i];
                nums[i] = tmp;
            }
        }
    }
    for (int i = 0; i < (numsSize-2); ++i)
    {
        for (int k = i+1; k < (numsSize-1); ++k)
        {
            for (int m = (numsSize-1); m > k; --m)
            {
                tmp = nums[i] + nums[k] + nums[m];
                if (tmp == target)
                {
                    return target;
                }
                else
                {
                    if (abs(tmp-target) < abs(ret-target))
                    {
                        ret = tmp;
                    }
                    if (tmp > target)
                    {
                        continue; //--m
                    }
                    else if (tmp < target)
                    {
                        break; //++k
                    }
                }
            }
        }
    }
    return ret;
}
