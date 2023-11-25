
class MyCircularDeque {
    vector<int> res;
    int head, tail, size;
public:
    MyCircularDeque(int k) : res(k, 0), size(0), head(0), tail(0) {

    }

    bool insertFront(int value) {
        if (isFull()) return false;
        
        if (size)
        if (head == 0) head = res.size() - 1;
        else head--;

        res[head] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        
        if (size)
        if (tail == res.size() - 1) tail = 0;
        else tail++;

        res[tail] = value;
        size++;
        return true;
    }

    bool deleteFront() {
    if (isEmpty()) return false;

    size--;
    if (size)
    if (head == res.size() - 1) head = 0;
    else head++;


    return true;
}

bool deleteLast() {
    if (isEmpty()) return false;
    
    size--;
    if(size)
    if (tail == 0) tail = res.size() - 1;
    else tail--;

    
    return true;
}

     int getFront() {
     return isEmpty()? -1: res[head];
 }

 int getRear() {
     return isEmpty() ? -1 : res[tail];
 }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == res.size();
    }
};
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
