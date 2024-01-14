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
    
    int maxres = 0;
    int in_counter(TreeNode* root, int& x)
    {
        if(!root || root->val != x) return 0;
       
        int left = in_counter(root->left,x);
        int right =  in_counter(root->right,x);
        maxres = max(maxres, left + right + 1);
        return max(left,right) + 1;
    }
    void in_helper(TreeNode* root, int& res)
    {
        if(!root) return;

        res = max(res, in_counter(root,root->val));
        in_helper(root->left,res);
        in_helper(root->right,res);

    }
    int longestUnivaluePath(TreeNode* root) {
        
        in_helper(root,maxres);
        return maxres ? maxres-1:0;

    }
};
