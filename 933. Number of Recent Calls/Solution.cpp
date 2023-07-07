class RecentCounter {
    private:
    queue<int> memo;
public:
    RecentCounter() {
        queue<int> empty;
        swap(memo,empty);
    }
    
    int ping(int t) {
        memo.push(t);
        while(memo.front() < t - 3000)
        {memo.pop();}
        return memo.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
