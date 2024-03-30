class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> memo(10001,0);
        int maxn = 0;
        for(auto x: nums)
        memo[x] += x,maxn = max(maxn,x);

        int cur = 0,pre = 0;

        for(int i = 0; i <= maxn;i++)
        {
            int temp = cur;
            cur = max(cur,pre + memo[i]);
            pre = temp;
        }

        return max(cur,pre);
    }
};
