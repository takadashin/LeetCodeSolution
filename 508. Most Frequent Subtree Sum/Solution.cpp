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
    int dfs_findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& keeptracking)
{
    if (root == NULL) return 0;

    root->val += dfs_findFrequentTreeSum(root->left, keeptracking) + dfs_findFrequentTreeSum(root->right, keeptracking);
    keeptracking[root->val]++;
    return  root->val;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    queue<TreeNode*> list;
    unordered_map<int, int> keeptracking;
    dfs_findFrequentTreeSum(root, keeptracking);
    int maxcounter = 0;

    vector<int> ans;
    for (auto x : keeptracking)
    {
        if (maxcounter == x.second)
            ans.push_back(x.first);
        else if (maxcounter < x.second)
        {
            ans.clear();
            ans.push_back(x.first);
            maxcounter = max(maxcounter, x.second);
        }
    }
    return ans;

}
};
