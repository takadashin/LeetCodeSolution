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
    
int findmaxindex(vector<int>& nums, int& l, int& r)
{
    int res = l;
    for (int i = l; i <= r; i++)
        if (nums[i] > nums[res])  res = i;

    return res;
}

TreeNode* helperDFS( vector<int>& nums,int l,int h)
{
    if (l > h) return NULL;

    if (l == h) {
        TreeNode* target = new TreeNode( nums[l]);
        return target;
    }
    else
    {
        int index = findmaxindex(nums, l, h);
        TreeNode* target = new TreeNode(nums[index]);
        target->left = helperDFS(nums, l, index - 1);
        target->right = helperDFS(nums, index + 1, h);
        return target;
    }

}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
 
    return helperDFS(nums, 0, nums.size() - 1);
}
};
