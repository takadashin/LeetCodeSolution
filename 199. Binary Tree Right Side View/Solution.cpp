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
    void preorder_goright(TreeNode* root,int step, vector<int>& res)
    {
        if(root == NULL) return ;
        if(res.size() < step)
        res.push_back(root->val);

        preorder_goright(root->right,step+1,res);

        preorder_goright(root->left,step+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        preorder_goright(root,1,res);

        return res;

    }
};
