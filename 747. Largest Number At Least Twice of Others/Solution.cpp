class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(!nums.size()) return -1;
        int maxn = 0;

        for(int i = 0; i < nums.size(); i++)
        if(nums[maxn] < nums[i])
        maxn = i;


        for(auto x: nums)
        {
            if(nums[maxn]  == x) continue;

            if(nums[maxn]  < x*2) return -1;
        }

        return maxn;
    }
};
