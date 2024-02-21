class KthLargest {
    int kt;
    priority_queue<int,vector<int>,greater<int>> memo;
public:
    KthLargest(int k, vector<int>& nums) {
        kt = k;
        for(auto x: nums)
        {
            add(x);
        }
    }
    
    int add(int val) {
        memo.push(val);
        if(memo.size() > kt) memo.pop();
        return memo.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
