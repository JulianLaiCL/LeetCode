/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (n <= 0) return head;
    if (head == NULL) return NULL;

    int len = 0;
    struct ListNode* plist = head;

    while (plist)
    {
        ++len;
        plist = plist->next;
    }
    //printf("len = %d\n", len);
    if (n > len) return head;

    //fine the target node
    plist = head;
    int cnt = len - n;

    if (cnt == 0)
    {
        head = head->next;
        free(plist);
        return head;
    }

    struct ListNode* preNode = head;
    do
    {
        preNode = plist;
        plist = plist->next;
    }
    while (--cnt);

    preNode->next = plist->next;
    free(plist);

    return head;
}
