/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
    if (digits == NULL || returnSize == NULL) return NULL;
    if (strlen(digits) == 0) return NULL;

    char mapping[8][5] =
    {
        'a', 'b', 'c', '\0', '\0',
        'd', 'e', 'f', '\0', '\0',
        'g', 'h', 'i', '\0', '\0',
        'j', 'k', 'l', '\0', '\0',
        'm', 'n', 'o', '\0', '\0',
        'p', 'q', 'r', 's', '\0',
        't', 'u', 'v', '\0', '\0',
        'w', 'x', 'y', 'z', '\0'
    };

    int len = strlen(digits);
    int size = 1;

    for (int i = 0; i < len; ++i)
    {
        if (((digits[i] - '0') < 2) || ((digits[i] - '0') > 9)) return NULL;
        size = size * strlen(mapping[(digits[i] - '0')-2]);
        //printf("len=%d\n", strlen(mapping[(digits[i] - '0')-2]));
    }
    *returnSize = size;

    //ASSUME caller will free it
    char** ansarr = malloc(sizeof(char*)*size);
    memset(ansarr, 0, sizeof(char*)*size);
    for (int i = 0; i < size; ++i)
    {
        ansarr[i] = malloc(sizeof(char)*(len+1));
        memset(ansarr[i], 0, sizeof(char)*(len+1));
    }
    //printf("size=%d\n", size);

    int gap = 0;
    char* ptr = NULL;
    int keylen = 0;

    for (int i = 0; i < len; ++i)
    {
        gap = 1;
        for (int m = i+1; m < len; ++m)
        {
            gap = gap * strlen(mapping[(digits[m] - '0')-2]);
        }
        //printf("GAP = %d\n", gap);
        keylen = strlen(mapping[(digits[i] - '0')-2]);
        for (int k = 0; k < size; ++k)
        {
            ptr = ansarr[k];
            *(ptr+i) = mapping[(digits[i] - '0')-2][(k/gap)%keylen];
        }
    }
    return ansarr;
}