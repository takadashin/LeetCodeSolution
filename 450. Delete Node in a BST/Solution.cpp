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
  



    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
        return NULL;
        else if(key < root->val) root->left =  deleteNode(root->left,key);
        else if(key > root->val) root->right = deleteNode(root->right,key);
        else
        {
            // found
            if(!root->left && !root->right)
                return NULL;
            else if( !root->right || !root->left )
                root = (root->left)? root->left:root->right;
            else
            {
                TreeNode* p = root->left;
                while( p->right)
                    p = p->right;
                root->val = p->val;
                root->left = deleteNode(root->left,p->val);

            }

           
        }
         return root;
    }

};
