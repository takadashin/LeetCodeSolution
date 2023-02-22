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
    int maxcount = 0,curcount = 0,curnum = -1;
    vector<int> res;

    void dfs_scanner(TreeNode* root)
    {
        if(root == NULL)
        return;

        
        dfs_scanner(root->left);

        
        curcount = (curnum == root->val) ? curcount+1: 1;
        curnum = root->val;
        if(curcount > maxcount)
        {
            res.clear();
            res.push_back(curnum);
            maxcount = max(curcount,maxcount);
        }
        else if(curcount == maxcount)
        {
            res.push_back(curnum);
        }
        dfs_scanner(root->right);
    }


    vector<int> findMode(TreeNode* root) {
        
        dfs_scanner(root);
        return res;


    }
};
