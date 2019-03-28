//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
char* longestCommonPrefix(char** strs, int strsSize) 
{
    if (strs == NULL || strsSize == 0) return "";
    if (strsSize == 1) return strs[0];

    int k = 0;
    bool bMatch = true;
    char c = '\0';
    
    while (bMatch)
    {
        c = strs[0][k];
        if (c == '\0') break;
        
        for (int i = 1; i < strsSize; ++i)
        {
            if (strs[i][k] != c)
            {
                bMatch = false;
                break;
            }
        }
        if (bMatch) ++k;
    }
    
    if (k > 0)
    {
        //assume caller will free str!!
        char* str = malloc(sizeof(char)*(k+1));
        strncpy(str, strs[0], k);
        str[k] = '\0';
        return str;
    }
    else
        return "";
}