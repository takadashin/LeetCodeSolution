class MyCircularQueue {
    vector<int> arr;
    int size, head, tail;
public:
    MyCircularQueue(int k) {
        arr.resize(k,-1);
        head = 0;
        tail = 0;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        arr[tail % size] = value;
        tail++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        arr[head % size] = -1;
        head++;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[head % size];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[(tail - 1) % size];
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return (tail - head ) == size ;
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
