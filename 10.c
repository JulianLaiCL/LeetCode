//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <stdlib.h>
bool isMatch(char* s, char* p)
{
    if (s == NULL || p == NULL) return false;
    int iLenStr = strlen(s);
    int iLenPat = strlen(p);
    bool bRet = false;
    bool **bArr = NULL;

    bArr = (int**)malloc(sizeof(int*)*(iLenStr+1));
    for (int i = 0; i <= iLenStr; ++i)
    {
        bArr[i] = (int*)malloc(sizeof(int)*(iLenPat+1));
        memset(bArr[i], false, sizeof(int)*(iLenPat+1));
    }

    bArr[0][0] = true;
    
    for (int k = 0; k < iLenPat; ++k)
    {
        if (*(p+k) == '*')
            bArr[0][k+1] = bArr[0][k-1];
        else
            bArr[0][k+1] = false;
        
    }
    for (int i = 0; i < iLenStr; ++i)
    {
        for (int k = 0; k < iLenPat; ++k)
        {
            if (*(s+i) == *(p+k))
                bArr[i+1][k+1] = bArr[i][k];
            if ('.' == *(p+k))
                bArr[i+1][k+1] = bArr[i][k];
            if ('*' == *(p+k))
            {
                if (*(p+k-1) == *(s+i) || *(p+k-1) == '.')
                    bArr[i+1][k+1] = bArr[i+1][k] | bArr[i][k+1] | bArr[i+1][k-1];
                else
                    bArr[i+1][k+1] = bArr[i+1][k-1];
            }
        }
    }
#if 0
    for (int i = 0; i < iLenStr+1; ++i)
    {
        if (i == 0) printf("  ");
        else printf("%c ", *(s+i-1));

        for (int k = 0; k < iLenPat+1; ++k)
        {
            printf("%d ", bArr[i][k]);
        }
        printf("\n");
    }
#endif
    bRet = bArr[iLenStr][iLenPat];
    for (int i = 0; i <= iLenStr; ++i)
    {
        free(bArr[i]);
    }
    free(bArr);
    return bRet;
}