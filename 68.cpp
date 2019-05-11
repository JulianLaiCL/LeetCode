#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        int size = words.size();
        if (size == 0) return {};

        int tmp = 0;
        int wordslen = 0; //accumulated length of words in one sentence
        int wordscnt = 0; //how many words are in one sentence
        int span = 0;
        string stmp;
        vector<string> vans;
        string sspace = " ";
        char cspace = ' ';
        
        for (int i = 0; i < size; ++i)
        {
            //Assume: Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
            tmp = wordslen = words[i].length(); 
            wordscnt = 1;
            stmp = words[i];
            int k = i + 1;
            
            //1st step: determin how many words could be in one stentence
            for (; k < size; ++k)
            {
                if (tmp + words[k].length() + 1 > maxWidth)
                    break;
                tmp += (words[k].length() + 1);
                wordslen += words[k].length();
                ++wordscnt;
            }

            //2nd step: distribute " " in one stentence
            if (wordscnt > 1)
            {
                span = (maxWidth-wordslen)/(wordscnt-1);
                tmp = (maxWidth-wordslen)%(wordscnt-1);
                for (int m = i+1; m < k; ++m)
                {
                    if (k == size) //last stentence
                    {
                        stmp = stmp + sspace;
                    }
                    else
                    {
                        for (int n = 0; n < span; ++n)
                            stmp = stmp + sspace;
                        if (tmp-- > 0)
                            stmp = stmp + sspace;
                    }
                    stmp = stmp + words[m];
                }
            }

            if (stmp.length() < maxWidth)
                stmp = stmp + string(maxWidth - stmp.length(), cspace);

            vans.push_back(stmp);
            i = k-1;
        }
        return vans;
    }
};

#if 0 //MYDEBUG
int main()
{
    Solution* sol = new Solution();
    vector<string> words;
    vector<string> vans;

    //words = {"This", "is", "an", "example", "of", "text", "justification."};
    //words = {"What","must","be","acknowledgment","shall","be"};
    //words = {};
    //words = {"Ayyyyyyyyyyyy","B","C", "DEF."};
    //words = {"A","B","C", "DEF."};
    //words = {"A","B","C", "DEF.", "KKMAN", "TEST123"};
    //words = {"A","B","C", "DEF.", "KKMANk", "TEST123"};
    words = {"Science","is","what","we","understand","well","enough","to","explain",
             "to","a","computer.","Art","is","everything","else","we","do"};
             
    vans = sol->fullJustify(words, 20);
    for (int i = 0; i < vans.size(); ++i)
    {
        cout<<vans[i]<<endl;
    }

    free(sol);
}
#endif
