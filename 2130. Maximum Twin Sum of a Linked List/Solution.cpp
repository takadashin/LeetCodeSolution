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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* pre = NULL,* cur = head, * nex = head->next;

        while(nex)
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;
        return cur;
    }


    int pairSum(ListNode* head) {

        ListNode* p = head;
        ListNode* half = head;
        while(p->next && p->next->next)
        {
            half = half->next;
            p=p->next->next;
        }

        half = reverseList(half);
        int res = 0;
        while(head)
        {
            
            res = max(res,head->val+half->val);
            head = head->next;
            half = half->next;
        }
        return res;
    }
};
