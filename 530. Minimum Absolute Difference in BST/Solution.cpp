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


    void dfs_count(TreeNode* root, int& mincount, int& memo)
    {
        if(root == NULL) return;
        
        dfs_count(root->left,mincount,memo);
        if(memo != -1)
        {
            
            mincount = min(mincount,abs(memo - root->val));
        }
        memo = root->val;
        
        dfs_count(root->right,mincount,memo);
    }
    int getMinimumDifference(TreeNode* root) {
     
        int res = INT_MAX;
        int memo = -1;
        dfs_count(root,res,memo);
        return res;
    }
};
