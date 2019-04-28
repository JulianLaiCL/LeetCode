#include <iostream>

using namespace std;

#define MYDEBUG 0
#if MYDEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
#endif

class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (k <= 0) return head; //invalid
        if (head == NULL) return NULL;
        
        int count = 0;
        ListNode* tmp = head;
        ListNode* newmiddle = head;
        ListNode* newtail = head;
        
        while(1)
        {
            while (newmiddle && count++ < k)
            {
                newmiddle = newmiddle->next;
            }

            if (newmiddle == NULL)
            {
                k %= count;
                count = 0;
                newmiddle = head;
                newtail = head;
            }
            else if (newmiddle == head)
            {
                return head;
            }
            else
            {
                break;
            }
        }
        
        //newtail is k-element away from newmiddle, and newmiddle is the last element of original list
        while (newmiddle && newmiddle->next != NULL)
        {
            newmiddle = newmiddle->next;
            newtail = newtail->next;
        }
        //link newmiddle to head, and link newtail to NULL
        tmp = head;
        head = newtail->next;
        newtail->next = NULL;
        newmiddle->next = tmp;
        
        return head;
    }
#if MYDEBUG
    void dump(ListNode* list)
    {
        while(list)
        {
            cout<<list->val<<"->";
            list = list->next;
        }
        cout<<"NULL"<<endl;
    }
#endif
};

#if MYDEBUG
int main()
{
    const int cnum = 5;
    Solution* sol = new Solution();
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    for (int i = 1; i <= cnum; ++i)
    {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    sol->dump(head);
    //sol->dump(sol->rotateRight(head, 4));
    //sol->dump(sol->rotateRight(head, 5));
    //sol->dump(sol->rotateRight(head, 6));
    //sol->dump(sol->rotateRight(head, 7));
    //sol->dump(sol->rotateRight(head, 1));
    //sol->dump(sol->rotateRight(head, 2000));
    sol->dump(sol->rotateRight(head, 2000000000));

    tmp = NULL;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(sol);
}
#endif
