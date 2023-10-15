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
    void dfs(TreeNode* root, string & res)
    {
        if (root == NULL) return ;
        res += to_string(root->val) ;
  
        
        if(root->left || root->right)
        {
            res += "(";

        if(root->left) dfs(root->left,res); 
         res += ")";
         
        if(root->right) res += "(",dfs(root->right,res), res += ")"; 
           
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string res = "";
        dfs(root,res);
        return res;
    }
};
