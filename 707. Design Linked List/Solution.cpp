class MyLinkedList {
    struct TreeNode{
        int val;
        TreeNode* next;
        TreeNode(int val)
        {
            this->val = val;
            this->next = NULL ;
        }
    };
    TreeNode* root;
    TreeNode* tail;
    int size;
public:
    MyLinkedList() {
        root = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {

        //printeveything();
        TreeNode* p = root;
        int counter = -1;
        while(p)
        {
            counter++;
            if(counter == index) return p->val;
            p = p->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        size++;
        if(!root) {addempty(val);return;}
        TreeNode * newhead = new TreeNode(val);
        newhead->next = root;
       
        root= newhead;
        
    }
    
    void addAtTail(int val) {
        size++;
        if(!root) {addempty(val);return;}
        TreeNode * newtail = new TreeNode(val);
        if(tail != nullptr) 
            tail->next = newtail;
        
        tail= newtail;
        
    }
    
    void addAtIndex(int index, int val) {
        if (index > size ) { return; }
        if (!root) { addempty(val); return; }
        if (index == 0) { addAtHead(val); return; }
        if (index == size ) { addAtTail(val); return; }
        
        size++;
        TreeNode* p = root;
        TreeNode* prev = nullptr;
        while(p && index--)
        {
            prev = p;
            p = p->next;
            }

        TreeNode * newnode = new TreeNode(val);
        prev->next = newnode;
        newnode->next = p;

    }
    
    void deleteAtIndex(int index) {
         if (index >= size  )  return;
        size--;

        if(!root) return;
        if(size == 0 ){
            root = NULL;
            tail = NULL;
            return;
        }
        int counter = index;
        if(index == 0) {root = root->next; return;}

        TreeNode* p = root;
        TreeNode* prev = NULL;
        while(p && counter--)
            {prev = p;
            p = p->next;}

   
        if (index == size  ) { 
        prev->next = NULL;
        tail = prev;
        return; }
        else
        prev->next = p->next;
        
    }
    void addempty(int val)
    {
  
        TreeNode * newhead = new TreeNode(val);
        newhead->next = root;
        tail = newhead;
        root= newhead;
    }

    void printeveything(){
        TreeNode* p = root;

        while(p )
            { cout << p->val << " | ";
            p = p->next;}
            cout << endl;
    }
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
