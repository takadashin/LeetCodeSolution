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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> st;
        vector<double> res;
        st.push(root);
        int lv_count = 1;
        int size = 1;
        long sum = 0;
        while(!st.empty())
        {
            lv_count = st.size();
            size = lv_count;
            sum = 0;
            while(lv_count--)
            {
                TreeNode* p = st.front();
                st.pop();

                sum += p->val;

                if(p->left) st.push(p->left);
                if(p->right) st.push(p->right);
            }

            res.push_back((double)sum/size);
        }

        return res;
    }
};
