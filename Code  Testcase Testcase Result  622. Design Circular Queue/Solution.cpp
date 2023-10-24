class MyCircularQueue {
    struct QNode {
        int val;
        QNode* next;
        QNode() {
            val = -1;
            next = NULL;
        }
    };

    QNode* root;
    QNode* tail;
    int size;
public:
    MyCircularQueue(int k) {
        root = new QNode();
        QNode* p = root;
        k--;
        while (k--)
        {
            p->next = new QNode();
            p = p->next;

        }
        p->next = root;
        tail = p;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
       
        tail = tail->next;
        tail->val = value;
       
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        root->val = -1;
        root = root->next;
        return true;
    }

    int Front() {
        return root->val;
    }

    int Rear() {
        return tail->val;
    }

    bool isEmpty() {
        return tail->next == root && root->val == -1;
    }

    bool isFull() {
        return tail->next == root && root->val != -1;
    }
};
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
