
int** threeSum(int* nums, int numsSize, int* returnSize)
{
    if ((nums == NULL) || (returnSize == NULL) || (numsSize < 3)) return NULL;
    int tmp = 0;
    int maxSize = 0; //max array size
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

    maxSize = 3;
    if (numsSize > 3)
    {
        for (int i = 3; i < numsSize; ++i)
        {
            if ((nums[i-3] == nums[i-2]) && (nums[i-2] == nums[i-1]) && (nums[i-1] == nums[i]))
            {
                continue;
            }
            ++maxSize;
        }
    }
    //printf("maxSize = %d\n", maxSize);
    maxSize = (maxSize - 1)*(maxSize -2)/2;
    //printf("pre allocate arr size = %d\n", maxSize);

    //assume caller will free it!
    ppArr = (int**)malloc(sizeof(int*)*maxSize);
    memset(ppArr, 0, sizeof(int*)*maxSize);

    for (int i = 0; i < maxSize; ++i)
    {
        ppArr[i] = (int*)malloc(sizeof(int)*3);
        memset(ppArr[i], 0, sizeof(int)*3);
    }
#if 0
    for (int i = 0; i < numsSize; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
#endif
    for (int i = 0; i < (numsSize-2); ++i)
    {
        for (int k = i+1; k < (numsSize-1); ++k)
        {
            if (/*(nums[i] != 0) &&*/ ((k+1) < (numsSize-2)) && (nums[k] == nums[k+1]) && (nums[k] == nums[k+2])) continue;
            tmp = nums[i] + nums[k];
            if (tmp > 0) break;
            if (tmp <= 0)
            {
                for (int m = (numsSize-1); m > k; --m)
                {
                    if (tmp + nums[m] < 0) break;
                    else if ((tmp + nums[m]) == 0)
                    {
                        dup = 0;
                        for (int n = 0; n < *returnSize; ++n)
                        {
                            if (ppArr[n][0] == nums[i] && ppArr[n][1] == nums[k])
                            {
                                dup = 1;
                                break;
                            }
                        }
                        if ((dup == 0) || (*returnSize == 0))
                        {
                            //printf("ANS = %d,%d,%d, [%d, %d, %d]\n", i, k, m, nums[i], nums[k], nums[m]);
                            ppArr[*returnSize][0] = nums[i];
                            ppArr[*returnSize][1] = nums[k];
                            ppArr[*returnSize][2] = nums[m];
                            ++(*returnSize);
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
