int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
#define MAX_NUM 4
    if ((nums == NULL) || (returnSize == NULL) || (numsSize < MAX_NUM)) return NULL;
    int tmp = 0;
    int maxSize = 1000; //max array size //FIXME
    int** ppArr = NULL;
    int dup = 0;
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

    //assume caller will free it!
    ppArr = (int**)malloc(sizeof(int*)*maxSize);
    memset(ppArr, 0, sizeof(int*)*maxSize);

    for (int i = 0; i < maxSize; ++i)
    {
        ppArr[i] = (int*)malloc(sizeof(int)*MAX_NUM);
        memset(ppArr[i], 0, sizeof(int)*MAX_NUM);
    }
#if 0
    for (int i = 0; i < numsSize; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
#endif

    for (int i = 0; i < (numsSize-(MAX_NUM-1)); ++i)
    {
        if ((i > 0) && (nums[i] == nums[i-1])) continue;
        for (int k = i+1; k < (numsSize-(MAX_NUM-2)); ++k)
        {
            if ((k > (i+1)) && (nums[k] == nums[k-1])) continue;
            for (int n = k+1; n < (numsSize-(MAX_NUM-3)); ++n)
            {
                if ((n > (k+1)) && (nums[n] == nums[n-1])) continue;

                for (int m = (numsSize-1); m > n; --m)
                {
                    if ((m < (numsSize-1)) && (nums[m] == nums[m+1])) continue;
                    
                    tmp = nums[i] + nums[k] + nums[n] +  nums[m];
                    if (tmp  < target) break; //move n to right
                    if (tmp  > target) continue; //move m to left
                    else //if (tmp == target)
                    {
                        //printf("ANS = %d,%d,%d,%d, [%d, %d, %d, %d]\n", i, k, n, m, nums[i], nums[k], nums[n], nums[m]);
                        ppArr[*returnSize][0] = nums[i];
                        ppArr[*returnSize][1] = nums[k];
                        ppArr[*returnSize][2] = nums[n];
                        ppArr[*returnSize][3] = nums[m];
                        ++(*returnSize);
                        if (*returnSize >= maxSize)
                        {
                            //do error handling here
                            printf("ERROR: Out of predefined array size!\n");
                        }
                    }
    
                }
            }
        }
    }
    
#if 0 //test only
    for (int i = 0; i < maxSize; ++i)
    {
        free(ppArr[i]);
    }
    free(ppArr);
#endif
    return ppArr;
}
                                                                  