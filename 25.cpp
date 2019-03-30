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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (k <= 1) return head;
        if (head == NULL) return NULL;
        
        //curNode = head;
        grouphead = head;
        groupend = head;
        while (groupend)
        {
            groupend = groupend->next;
            if (groupend == NULL) break; //cannot group
            
            ++groupsize;
            if (groupsize == k)
            {
                groupnext = groupend->next;
                groupend->next = NULL;
                //reverse linked list
                if (grouppre)
                    grouppre->next = reverse(grouphead);
                else
                    newhead = reverse(grouphead);
                grouppre = grouphead; //will be the end of pre group
                grouphead->next = groupnext;
                grouphead = groupnext;
                groupend = groupnext;
                groupsize = 1; //reset
            }
        }
        if (newhead == NULL) return head;
        else return newhead;
    }
private:
    ListNode* grouphead = NULL;
    ListNode* groupend = NULL;
    ListNode* newhead = NULL;
    ListNode* groupnext = NULL;
    ListNode* grouppre = NULL;
    int groupsize = 1;
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = NULL, *next = NULL, *cur = NULL;
        cur = head;
        
        while (cur != NULL) 
        { 
            next = cur->next; 
            cur->next = pre; 
            pre = cur; 
            cur = next; 
        } 
        head = pre;
        return head;
    }
};

#if 0
int main()
{
    ListNode* head = new ListNode(1);
    ListNode* curNode = head;
    ListNode* tmp = NULL;

    for (int i = 2; i< 9; ++i)
    {
        tmp = new ListNode(i);
        curNode->next = tmp;
        curNode = tmp;
    }

    tmp = head;
    while (tmp)
    {
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
    
    Solution sol;
    head = sol.reverseKGroup(head,3);

    tmp = head;
    while (tmp)
    {
        cout<<tmp->val<<"->";
        free(tmp); //fine if tmp is free
        tmp = tmp->next;
    }
    cout<<endl;

    return 0;
}
#endif