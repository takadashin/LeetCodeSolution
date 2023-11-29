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

    bool helper(TreeNode* root,set<int>& vi,int& k)
    {
        if(!root) return false;
        if(vi.count(k-root->val)) return true;
        
        vi.insert(root->val);
        return helper(root->left,vi,k) || helper(root->right,vi,k);
    }
    bool findTarget(TreeNode* root, int k) {
       
        set<int> vi;

        return helper(root,vi,k);

    }
};
