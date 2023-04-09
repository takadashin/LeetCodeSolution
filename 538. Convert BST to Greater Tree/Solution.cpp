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
    
void sumconvertBST(TreeNode* root,int& sumcollector)
{
    if (root == NULL)
        return;
    else
    {
        sumconvertBST(root->right, sumcollector);
       sumcollector += root->val;
        root->val = sumcollector;
        
        sumconvertBST(root->left, sumcollector);
    }
}
TreeNode* convertBST(TreeNode* root) {
    int counter = 0;
    sumconvertBST(root, counter);
    return root;
}
};
