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
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,unsigned long long>> qe;

        qe.push({root,0});

        int sz, res = 0;
        int left = -1,right = -1;unsigned long long index;
        while(!qe.empty())
        {
            sz = qe.size();
            res = max(res,right - left +1);
            left = right = -1;
            while(sz--)
            {
                TreeNode* q = qe.front().first;
                index = qe.front().second;
                qe.pop();

                left = (left == -1 )? index : left;
                right = index;
        
                if(q->left) qe.push({q->left,index* 2 + 1});
                if(q->right) qe.push({q->right,index * 2 + 2});

            }
        }
        return max(res, right - left + 1);
    }
};
