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

    bool compare(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot) return true;
        else if(!root || !subRoot) return false;
        if( root->val != subRoot->val) return false;
        return root->val == subRoot->val && compare(root->left,subRoot->left) && compare(root->right,subRoot->right);
       

        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(compare(root,subRoot)) return true;
            
        bool res = (root->left)? isSubtree(root->left,subRoot):false ;
        if(res) return true;
        res = (root->right)?isSubtree(root->right,subRoot):false;
        if(res) return true;
        return false;
        
    }
};
