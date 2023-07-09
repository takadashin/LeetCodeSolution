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

    int helperpathSum(TreeNode* root, long long targetSum)
    {
        if (root == NULL) return 0;
    else
    {
        int res =0;
        if (targetSum == root->val)res++;
         
        res += helperpathSum(root->left, targetSum - root->val) + helperpathSum(root->right, targetSum - root->val) ;
    
        return res;
    }}
    int pathSum(TreeNode* root, int targetSum) {
    if (root == NULL) return 0;
    int res = helperpathSum(root, targetSum) ;
    res +=  pathSum(root->left, targetSum) + pathSum(root->right, targetSum) ;

        return res;
    }




};
