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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) 
        {
             TreeNode* newRoot = new TreeNode(val);
                        newRoot->left = root;
                        return newRoot;
        }
        queue<TreeNode*> chk;
        depth--;
        
        chk.push(root);

        int counter = chk.size();
        TreeNode* leftNode,*p,*p2,*rightNode;
        while(!chk.empty() && depth)
        {
            depth--;
            if(!depth)
            {
                while(!chk.empty()){
                    p2 = chk.front();
                    chk.pop();
                    //if(p2->left) {
                         leftNode = new TreeNode(val);
                        leftNode->left = p2->left;
                        p2->left = leftNode;
                    //}
                    //if(p2->right) {
                        rightNode = new TreeNode(val);
                        rightNode->right = p2->right;
                        p2->right = rightNode;
                    //}
                    
                    

                }
                return root;

            }

            counter = chk.size();
            while(counter--)
            {
                 p = chk.front();
                chk.pop();

                if(p->left) chk.push(p->left);
                if(p->right) chk.push(p->right);
            }
        }
        
        return root;

    }
};
