char* intToRoman(int num) 
{
#define MAX_LEN 16
    if (num >= 4000 || num <= 0) return NULL;
    //assume caller will free str!!
    char* str = malloc(sizeof(char)*MAX_LEN);
    memset(str,'\0', sizeof(char)*MAX_LEN);
    char* p = str;
    while (num >= 1000)
    {
        num-=1000;
        //printf("M");
        sprintf(p, "M");
        ++p;
    }
    while (num >=900)
    {
        num-=900;
        //printf("CM");
        sprintf(p, "CM");
        p+=2;
    }
    while (num >=500)
    {
        num-=500;
        //printf("D");
        sprintf(p, "D");
        ++p;
    }
    while (num >=400)
    {
        num-=400;
        //printf("CD");
        sprintf(p, "CD");
        p+=2;
    }
    while (num >=100)
    {
        num-=100;
        //printf("C");
        sprintf(p, "C");
        ++p;
    }
    while (num >=90)
    {
        num-=90;
        //printf("XC");
        sprintf(p, "XC");
        p+=2;
    }
    while (num >=50)
    {
        num-=50;
        //printf("L");
        sprintf(p, "L");
        ++p;
    }
    while (num >=40)
    {
        num-=40;
        //printf("XL");
        sprintf(p, "XL");
        p+=2;
    }
    while (num >=10)
    {
        num-=10;
        //printf("X");
        sprintf(p, "X");
        ++p;
    }
    while (num >=9)
    {
        num-=9;
        //printf("IX");
        sprintf(p, "IX");
        p+=2;
    }
    while (num >=5)
    {
        num-=5;
        //printf("V");
        sprintf(p, "V");
        ++p;
    }
    while (num >=4)
    {
        num-=4;
        //printf("IV");
        sprintf(p, "IV");
        p+=2;
    }
    while (num >=1)
    {
        num-=1;
        //printf("I");
        sprintf(p, "I");
        ++p;
    }
    //printf("\n");
    return str;
}