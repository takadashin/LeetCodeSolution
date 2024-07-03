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

    void dfs(TreeNode* root,int& mins,int& prev)
    {
        if(!root) return;
        
        dfs(root->left,mins,prev);

        if(prev != -1) 
        
        mins = min(mins,root->val - prev) ;
        prev = root->val;

        dfs(root->right,mins,prev);

    }
    int minDiffInBST(TreeNode* root) {
        int mins = INT_MAX,prev = -1;
        dfs(root,mins,prev);
        return mins;
        
        
    }
};
