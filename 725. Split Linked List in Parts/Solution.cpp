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
    
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = 0;
    ListNode* p = head;
    vector<ListNode*> ans;
    while (p)
    {
        n++;
        p = p->next;
    }
    vector<int> how;
    while (k)
    {
        int ele = n / k;
        how.insert(how.begin(), ele);
        n -= ele;
        k--;
    }

    ListNode* newhead = head;
    for (auto x : how)
    {
        ans.push_back(newhead);
        ListNode* p = newhead, * pre = NULL;

        while (x--)
        {
            pre = p;
            p = p->next;
        }
        if (newhead)
        {
            newhead = p;
            pre->next = nullptr;
        }


    }
   
    return ans;
}
};
