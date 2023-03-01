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

    int maxlevel = 0;
    void dfs_findBottomLeftValue(TreeNode* root,TreeNode*& lefty,int level)
    {
        if(root == NULL) return;

        dfs_findBottomLeftValue( root->left, lefty,level+1);
        dfs_findBottomLeftValue( root->right, lefty,level+1);

        if(maxlevel < level)
        {
            maxlevel = level;
            lefty = root;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
    maxlevel = 0;
    TreeNode* lefty = root;
    int level = 0;
    dfs_findBottomLeftValue( root, lefty,level);
    return lefty->val;
}
};
