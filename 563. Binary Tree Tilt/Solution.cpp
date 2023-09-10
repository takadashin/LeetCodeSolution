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

    int sumbulshit(TreeNode* root)
{
    if (root == NULL) return 0;
    return root->val + (root->left ? sumbulshit(root->left) : 0) + (root->right ? sumbulshit(root->right) : 0);
}
   
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;
        return  abs(sumbulshit(root->right) -  sumbulshit(root->left))  + findTilt(root->right) + findTilt(root->left) ;

    }
};
