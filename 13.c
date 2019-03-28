int romanToInt(char* s) 
{
    //Input is guaranteed to be within the range from 1 to 3999.
    if (s == NULL) return 0;
    if (strlen(s) == 0) return 0;
    
    int iAns = 0;
    while (*s != '\0')
    {
        if (*s == 'M') iAns+=1000;
        else if (*s == 'D') iAns+=500;
        else if (*s == 'L') iAns+=50;
        else if (*s == 'V') iAns+=5;
        else if (*s == 'C')
        {
            if (*(s+1) == 'M')
            {
                iAns+=900;
                ++s;
            }
            else if (*(s+1) == 'D')
            {
                iAns+=400;
                ++s;
            }
            else iAns+=100;
        }
        else if (*s == 'X')
        {
            if (*(s+1) == 'C')
            {
                iAns+=90;
                ++s;
            }
            else if (*(s+1) == 'L')
            {
                iAns+=40;
                ++s;
            }
            else iAns+=10;
        }
        else if (*s == 'I')
        {
            if (*(s+1) == 'X')
            {
                iAns+=9;
                ++s;
            }
            else if (*(s+1) == 'V')
            {
                iAns+=4;
                ++s;
            }
            else iAns+=1;
        }
        ++s;
    }
    return iAns;
}