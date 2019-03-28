#if 0
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        int tmp;
        ListNode* newhead = head;
        
        while (head)
        {
            if (head->next)
            {
                tmp = head->val;
                head->val = head->next->val;
                head->next->val = tmp;
                for (int i = 0; i < 2; ++i)
                {
                    if (head->next) head = head->next; 
                }
            }
            else
            {
                return newhead;
            }
        }
        return newhead;
    }
};

#if 0
int main()
{
    ListNode* head = new ListNode(3);
    ListNode* tmp = head;
    for(int i = 2; i < 8; i=i+3)
    {
        ListNode* node = new ListNode(i);
        tmp->next = node;
        tmp = tmp->next;
    }

    tmp = head;
    while(tmp)
    {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout<<endl;

    Solution sol;
    head = sol.swapPairs(head);
    
    tmp = head;
    while(tmp)
    {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout<<endl;

    return 0;
}
#endif