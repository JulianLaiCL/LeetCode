#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    if (l1 == NULL && l2) return l2;
    if (l2 == NULL && l1) return l1;
    if (l1 == NULL && l2 == NULL) return NULL;
    
    struct ListNode* head = NULL, *ptr = NULL;
    
    if (l1->val < l2->val)
    { 
        head = ptr = l1; 
        l1 = l1->next; 
    }
    else                   
    { 
        head = ptr = l2; 
        l2 = l2->next;
    }

    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL && l2 != NULL)
        {
            ptr->next = l2;
            break;
        }
        if (l2 == NULL && l1 != NULL)
        {
            ptr->next = l1;
            break;
        }
        if (l1->val < l2->val) 
        { 
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        else
        { 
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
    }
    return head;
}

int main()
{
   struct ListNode* head1 = NULL, *node1 = malloc(sizeof(struct ListNode));
   node1->next = NULL;
   node1->val = -5;
   head1 = node1;
   for (int i = 0; i < 10 ; i=i+2)
   {
       node1->next = malloc(sizeof(struct ListNode));
       node1 = node1->next;
       node1->val = i;
       node1->next = NULL;
   }
   node1 = head1;
   while(node1)
   {
       printf("%d->", node1->val);
       node1 = node1->next;
   }
   printf("\n");
   struct ListNode* head2 = NULL, *node2 = malloc(sizeof(struct ListNode));
   node2->next = NULL;
   node2->val = -2;
   head2 = node2;
   for (int i = 1; i < 3 ; i=i+2)
   {
       node2->next = malloc(sizeof(struct ListNode));
       node2 = node2->next;
       node2->val = i;
       node2->next = NULL;
   }
   node2 = head2;
   while(node2)
   {
       printf("%d->", node2->val);
       node2 = node2->next;
   }
   printf("\n\n");
   //struct ListNode* head3 = mergeTwoLists(head1, head2);
   struct ListNode* head3 = mergeTwoLists(NULL, NULL);
   struct ListNode* tmp = NULL;
   while(head3)
   {
       printf("%d->", head3->val);
       tmp = head3;
       head3 = head3->next;
       free(tmp);
   }

   return 0;
}