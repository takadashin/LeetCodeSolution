class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n+1,0);
        vector<double> memo(n,0);

        for(int i = 0 ;i < n;i++)
            prefix[i+1] = prefix[i] + nums[i];
        
        for(int i = 0 ;i < n;i++)
        memo[i] = (prefix[n] - prefix[i]) / (n - i);

        for(int z = 0; z < k-1;z++)
        for(int i = 0 ;i < n;i++)
        for(int j = i+1 ;j < n;j++)
        memo[i] = max(memo[i],(prefix[j] - prefix[i]) / (j - i) + memo[j] );

        return memo[0];
    }
};
