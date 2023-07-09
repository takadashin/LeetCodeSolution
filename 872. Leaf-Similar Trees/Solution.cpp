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

    void preorderCO(TreeNode* root,vector<int>& col)
    {
        if(root == NULL) return;
        else if(root->left == NULL && root->right == NULL)
        col.push_back(root->val);
        else
        {
            preorderCO(root->left,col);
            preorderCO(root->right,col);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left,right;

        preorderCO(root1,left);

        preorderCO(root2,right);
        if(left.size() != right.size()) return false;
        for(int i = 0;i < left.size();i++)
        if(left[i] != right[i])
        return false;
        return true;
    }
};
