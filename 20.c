#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Given a string containing just the characters '(', ')', '{', '}', '['
bool isValid(char* s)
{
    if (s == NULL) return true;
    int len = strlen(s);
    if (len == 0) return true;
 
    char* ps = malloc(len);
    memset(ps, 0, sizeof(char)*len);
    int idx = 0;
    
    while(*s != '\0')
    {
        if (*s == '(')
        {
            ps[idx++] = '(';
        }
        else if (*s == ')')
        {
            if (idx == 0 || ps[--idx] != '(')
            {
                free(ps);
                return false;
            }
        }
        else if (*s == '{')
        {
            ps[idx++] = '{';
        }
        else if (*s == '}')
        {
            if (idx == 0 || ps[--idx] != '{')
            {
                free(ps);
                return false;
            }
        }
        else if (*s == '[')
        {
            ps[idx++] = '[';
        }
        else if (*s == ']')
        {
            if (idx == 0 || ps[--idx] != '[')
            {
                free(ps);
                return false;
            }
        }
        else
        {
            free(ps);
            return false;
        }
        ++s;
    }
    
    free(ps);
    if (idx) return false;
    return true;
}

int main()
{
    printf("isValid(())=%d\n", isValid("()"));
    printf("isValid(()[]{})=%d\n", isValid("()[]{}"));
    printf("isValid((])=%d\n", isValid("(]"));
    printf("isValid(([)])=%d\n", isValid("([)]"));
    printf("isValid(([{)]})=%d\n", isValid("([{)]}"));
    printf("isValid({[()]})=%d\n", isValid("{[()]}"));
    printf("isValid(])=%d\n", isValid("]"));
    printf("isValid([)=%d\n", isValid("["));
    return 0;
}