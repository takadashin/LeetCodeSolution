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


    void preorder_help(TreeNode* root,int& counter,int maxnode)
    {
        if(root == NULL)
        return;
        else
        {
            if(root->val >= maxnode) {counter++;maxnode = root->val;};

            preorder_help(root->left,counter,maxnode);
            preorder_help(root->right,counter,maxnode);

        }
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
         preorder_help(root,res,root->val);
        return res;
    }
};
