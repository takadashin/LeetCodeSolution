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

    int res  = 0;
    void helper(TreeNode* root,bool left, int step)
    {
        if(root == NULL) return;
        res = max(res,step);

        if(left)
        {
            //go left;
            helper(root->left,!left,step+1);
            helper(root->right,left,1);
        }
        else
        {
            helper(root->right,!left,step+1);
            helper(root->left,left,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        helper(root,true,0);
        helper(root,false,0);

        return res;
    }
};
