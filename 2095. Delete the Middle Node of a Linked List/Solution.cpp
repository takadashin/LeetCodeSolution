/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
ListNode* deleteMiddle(ListNode* head) {
    ListNode* p = head;
    if(p == NULL || p->next == NULL) return NULL;
  
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    int secondsize = 0;
    p = head;
    int mid = size / 2;
    while (secondsize != mid-1)
    {
        secondsize++;
        p = p->next;
    }

    
  
    p->next = (p->next) ? p->next->next : NULL;

    return head;
}
};
