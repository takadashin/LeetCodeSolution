/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
    if(root == NULL) return {};
    vector<int> res;
    stack<Node*> stk;
Node* target,* x;
    stk.push(root);
   
    while (!stk.empty())
    {
         target = stk.top();
        stk.pop();
        res.push_back(target->val);
        for (int i = 0; i < target->children.size(); i++)
        {
            x = target->children[i];
            stk.push(x);
        }
    }
    reverse(res.begin(),res.end());
    return res;
    }
};
