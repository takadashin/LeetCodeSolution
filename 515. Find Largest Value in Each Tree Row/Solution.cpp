/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> list;
        list.push(root);
        int depth = 0;
        vector<int> ans;
        int counter = list.size();
        TreeNode* maxnode = root;
        while(!list.empty())
        {
            depth++;
            counter = list.size();
            maxnode = list.front();
            while(counter--)
            {
                TreeNode* p = list.front();
                if(maxnode->val < p->val) maxnode = p;
                list.pop();
                if(p->left) list.push(p->left);
                if(p->right) list.push(p->right);
            }

            ans.push_back(maxnode->val);




        }

        return ans;
    }
};
