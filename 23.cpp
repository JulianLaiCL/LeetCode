#if 0
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        size = lists.size();
        //cout << "size=" << lists.size() << endl;
        vector<ListNode*> vptr(size);
        for (int i = 0; i < size; ++i)
        {
            vptr[i] = lists[i];
        }
        while(1)
        {
            min_val = INT_MAX;
            min_idx = -1;
            for (int i = 0; i < size; ++i)
            {
                if (vptr[i] && min_val > vptr[i]->val)
                {
                    min_val = vptr[i]->val;
                    min_idx = i;
                }
            }
            if (min_idx == -1) break;
            if (merged_head == NULL)
            {
                merged_head = vptr[min_idx];
                merged_tmp = merged_head;
                vptr[min_idx] = vptr[min_idx]->next;
            }
            else
            {
                merged_tmp->next = vptr[min_idx];
                merged_tmp = vptr[min_idx];
                vptr[min_idx] = vptr[min_idx]->next;
            }
        }
        return merged_head;
    }
private:
    ListNode* merged_head;
    ListNode* merged_tmp;
    int size = 0;
    int min_val = INT_MAX;
    int min_idx = -1;
};

#if 0
int main()
{
    vector<ListNode*> lists(3, NULL);
    ListNode* head = new ListNode(0);
    lists[0] = head;
    for(int i = 1; i < 10; i=i+2)
    {
        ListNode* tmp = new ListNode(i);
        head->next = tmp;
        head = head->next;
    }
    ListNode* head2 = new ListNode(0);
    lists[1] = head2;
    for(int i = 2; i < 10; i=i+1)
    {
        ListNode* tmp = new ListNode(i);
        head2->next = tmp;
        head2 = head2->next;
    }
    ListNode* head3 = new ListNode(0);
    lists[2] = head3;
    for(int i = 3; i < 10; i=i+3)
    {
        ListNode* tmp = new ListNode(i);
        head3->next = tmp;
        head3 = head3->next;
    }
    for(int i = 0; i < lists.size(); ++i)
    {
        ListNode* tmp = lists[i];
        while(tmp)
        {
            cout <<tmp->val<<"->";
            tmp = tmp->next;
        }
        cout<<endl;
    }

    Solution sol;
    ListNode* tmp = sol.mergeKLists(lists);
    while(tmp)
    {
        cout <<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
    return 0;
}
#endif