
class Solution {
public:

    

    vector<int> preorder(Node* root) {
    if (root == NULL) return{};
    vector<int> res;
    stack<Node*> stk;

    stk.push(root);
    while (!stk.empty())
    {
        Node* target = stk.top();
        stk.pop();
        res.push_back(target->val);
        for (int i = target->children.size() -1; i >= 0; i--)
        {
            Node* x = target->children[i];
            
            stk.push(x);
        }
    }
    return res;
}
};
