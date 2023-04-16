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
    
int helperdiameter(TreeNode* root, int& length)
{
    if (root == NULL)
        return 0;
    else
    {
        int cal1 = 0,cal2 = 0;
        if (root->left != NULL)
            cal1 = helperdiameter(root->left , length) + 1;
        if (root->right != NULL)
            cal2 = helperdiameter(root->right, length) + 1;


        length = max(length, cal1 + cal2);
        return max(cal1, cal2);
    }
}
int diameterOfBinaryTree(TreeNode* root) {
    int length = 0;
    int temp = helperdiameter(root, length);
    return length;
}
};
