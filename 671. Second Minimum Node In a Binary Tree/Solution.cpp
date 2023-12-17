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

    void dps(TreeNode * root,int& sm1,int& sm2)
    {
        if(!root) return;

        if(root->val < sm1 || sm1 == -1)
        {
            sm2 = sm1;
            sm1 = root->val;
        }
        else if (root->val > sm1 && (root->val < sm2 || sm2 == -1)) sm2 = root->val;
        
        dps(root->left,sm1,sm2);
        dps(root->right,sm1,sm2);


    }
    int findSecondMinimumValue(TreeNode* root) {
        int sm1 = -1,sm2 = -1;

        dps(root,sm1,sm2);
        return sm2;
    }
};
