class Solution {
public:
    Node* helper(Node* q1, Node* q2)
    {
        

        //base case
        if((q1->isLeaf  && q1->val) ||( q2->isLeaf && q2->val))
        {
            return (q1->isLeaf  && q1->val)  ? q1:q2;

        }
        else if(q1->isLeaf|| q2->isLeaf  )
        { 
            return q1->isLeaf ? q2:q1;
        }
        
            Node* target = new Node();
            target->isLeaf = 0;
            target->val  = 1 ;
            target->topLeft =  helper(q1->topLeft,q2->topLeft);
            target->topRight =  helper(q1->topRight,q2->topRight);
            target->bottomLeft =  helper(q1->bottomLeft,q2->bottomLeft);
            target->bottomRight =  helper(q1->bottomRight,q2->bottomRight);
            if (target->topLeft->isLeaf && target->topRight->isLeaf  && target->bottomLeft->isLeaf  && target->bottomRight->isLeaf &&
            target->topLeft->val && target->topRight->val  && target->bottomLeft->val  && target->bottomRight->val)
            {target->isLeaf = 1;
            target->topLeft = target->topRight  = target->bottomLeft  = target->bottomRight = NULL;}
        
        
        return target;
    }
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node* newroot = helper(quadTree1,quadTree2);
        return newroot;
    }
};
