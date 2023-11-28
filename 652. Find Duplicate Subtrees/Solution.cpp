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

    
string dfsstr(TreeNode* root, map<string,int>& mp, vector<TreeNode* >& res) {
    if (!root) return "";
    string ans = to_string(root->val) + "-" +  dfsstr(root->left,mp,res) + "-" + dfsstr(root->right,mp,res);
    if (mp[ans]++ == 1)
        res.push_back(root);


    return ans;


}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    map<string,int> mp;
    vector<TreeNode*> res;
    dfsstr(root, mp, res);

    return res;


}
};
