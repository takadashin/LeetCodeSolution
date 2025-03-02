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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> test;

        for(auto x: nums) test.insert(x);

        ListNode* p = head;
        int counter = 0;
        bool connect = false;
        while(p)
        {
            if(!connect )
            {
                if(test.count(p->val) > 0)
                {connect = true;
                counter++;}
            }
            else
                if(test.count(p->val) == 0) connect = false;

            p = p->next;
        }

        return counter;
    }
};
