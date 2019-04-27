#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm> //remove()
#include <numeric> //iota()

using namespace std;

class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        if (n <= 0 || k <=0) return ""; //invalid input
        int total = 1;
        for (int i = 2; i <= n; ++i)
            total *= i;
        if (k > total) return "";
        --k; //start from idx zero
        
        vector<int> vpat(n);
        std::iota(vpat.begin(), vpat.end(), 1);
        string sans;
        int group_num = total;
        int group_idx = 0;
        while(n)
        {
            group_num = group_num/(n--);
            group_idx = k/group_num;
            sans += to_string(vpat[group_idx]);
            std::remove(vpat.begin(), vpat.end(), vpat[group_idx]);
            k = k%group_num;
        }
        //cout<<sans<<endl;
        return sans;
    }
};

#if 0
int main()
{
    Solution* sol = new Solution();
    assert("2314" == sol->getPermutation(4,9));
    assert("213" == sol->getPermutation(3,3));
    assert("1234" == sol->getPermutation(4,1));
    assert("321" == sol->getPermutation(3,6));

    free(sol);
}
#endif
