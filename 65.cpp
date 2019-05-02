#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib> //strtod()
#include <algorithm> //remove()

using namespace std;

class Solution 
{
public:
    bool isNumber(string s) 
    {
        if (s.length() == 0) return false;
        //s.erase(remove(s.begin(), s.end(), ' '), s.end());
        //if (s.length() == 0) return false;
        auto itstart = s.begin();
        auto itend = s.end();
        while (itstart != itend && *itstart == ' ') ++itstart;
        if (itstart == itend) return false;
        do
        {
            --itend;    
        }
        while (itend != itstart && *itend == ' ');
        s = string(itstart, itend+1);

        char* pEnd = NULL;
        strtod (s.c_str(), &pEnd);
                
        if (*pEnd != NULL)
            return false;

        return true;
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();

    //"0" => true
    assert(1 == sol->isNumber("0"));
    //" 0.1 " => true
    assert(1 == sol->isNumber(" 0.1 "));
    //"abc" => false
    assert(0 == sol->isNumber("abc"));
    //"1 a" => false
    assert(0 == sol->isNumber("1 a"));
    //"2e10" => true
    assert(1 == sol->isNumber("2e10"));
    //" -90e3   " => true
    assert(1 == sol->isNumber(" -90e3   "));
    //" 1e" => false
    assert(0 == sol->isNumber(" 1e"));
    //"e3" => false
    assert(0 == sol->isNumber("e3"));
    //" 6e-1" => true
    assert(1 == sol->isNumber(" 6e-1"));
    //" 99e2.5 " => false
    assert(0 == sol->isNumber(" 99e2.5 "));
    //"53.5e93" => true
    assert(1 == sol->isNumber("53.5e93"));
    //" --6 " => false
    assert(0 == sol->isNumber(" --6 "));
    //"-+3" => false
    assert(0 == sol->isNumber("-+3"));
    //"95a54e53" => false
    assert(0 == sol->isNumber("95a54e53"));
    assert(1 == sol->isNumber("-8"));
    assert(1 == sol->isNumber("-9e8"));
    assert(1 == sol->isNumber("-0.000e9"));
    assert(0 == sol->isNumber("       "));
    assert(0 == sol->isNumber(""));
    assert(1 == sol->isNumber(".1"));
    assert(0 == sol->isNumber(".  1"));
    assert(0 == sol->isNumber("   .  1   "));
    assert(1 == sol->isNumber("   .1"));

    free(sol);
}
#endif
