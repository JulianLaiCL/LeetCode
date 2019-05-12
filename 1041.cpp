#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution 
{
public:
    bool isRobotBounded(string instructions) 
    {
        int result = 0;
        int move = 0;
        int turn = 0;
        for (int i = 0; i < instructions.length(); ++i)
        {
            if (instructions[i] == 'L')
            {
                --result;
                turn = 1;
            }
            else if (instructions[i] == 'R')
            {
                ++result;
                turn = 1;
            }
            else
            {
                move = 1;
            }
            result %= 4;
        }
        cout<<"result, turn, move = "<<result<<","<<move<<endl;
        if (result != 0 && move == 1) return true;
        else if (result == 0 && turn == 1) return true;
        else if (move == 0) return true;
        else return false;
    }
};

#if 1 //MYDEBUG
int main()
{
    Solution* sol = new Solution();

    //TRUE
    cout<<sol->isRobotBounded("GGRGGRGGRGGR")<<endl;
    //FALSE
    assert(0 == sol->isRobotBounded("LLLLGGRRRR"));
    //TRUE
    assert(1 == sol->isRobotBounded("LLGG"));
    //FALSE
    assert(0 == sol->isRobotBounded("LLGGLL"));
    //FALSE
    assert(0 == sol->isRobotBounded("LLLRLLLRLLGLLGGRGLLLGGLRRRRRGLRLRLRLGGRGRGRLLLLLLGLLRLGLGLRLGGGRR"));
    //TRUE
    assert(1 == sol->isRobotBounded("LRRRRLLLRL"));
    //TRUE
    assert(1 == sol->isRobotBounded("GGLLGG"));
    //FALSE
    assert(0 == sol->isRobotBounded("GG"));
    //TRUE
    assert(1 == sol->isRobotBounded("GL"));

    cout<<"PASS!"<<endl;
    free(sol);
}
#endif
