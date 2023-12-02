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

    int depth(TreeNode* root)
    {
        if(!root) return 0;
        else return max(depth(root->left),depth(root->right)) + 1;
    }

    void helper(TreeNode* root,vector<vector<string>>& res,int l ,int r,int level)
    {
        if(!root) return;
        int mid = l + (r-l) /2;
        
        res[level][mid] = to_string(root->val);
        if(root->left) helper(root->left,res,l,mid-1,level+1);
        if(root->right) helper(root->right,res,mid+1,r,level+1);
        
    }
    vector<vector<string>> printTree(TreeNode* root) {

        int len = 1;
        int dep = depth(root);

        for(int i =1 ;i < dep;i++)
            len = 1 + len*2;

        
        vector<vector<string>> res(dep,vector<string>(len,""));

        helper(root,res,0,len,0);


        return res;
    }
};
