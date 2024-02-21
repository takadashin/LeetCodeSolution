class MyHashSet {
    vector<bool> memo;
public:
    MyHashSet() {
        memo = vector<bool>(1e6+1,false);
    }
    
    void add(int key) {
        memo[key] = true;
    }
    
    void remove(int key) {
        memo[key] = false;
    }
    
    bool contains(int key) {
        return memo[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
