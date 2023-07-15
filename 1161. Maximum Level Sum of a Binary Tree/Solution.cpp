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


    void dfsleveling(TreeNode* root,int level,vector<int>& res)
    {
        if(root == NULL) return;

        if(res.size() < level)
        res.push_back(root->val);
        else
        res[level-1] += root->val;

        dfsleveling(root->left,level+1,res);
        dfsleveling(root->right,level+1,res);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> res;

        dfsleveling(root,1,res);
        int ret = INT_MIN,index = -1;
        for(int i = 0;i < res.size();i++)
        {
            if(res[i] > ret)
            {
                ret = res[i];
                index = (i+1);
            }
        }

        return index;
    }
};
