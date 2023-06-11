class Solution {
public:
    int checkRecord(int n) {
        const int mod = 1e9 + 7;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        dp[0][0][0] = 1; // base case
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 0;j <= 1;j ++)
            for(int k = 0;k <= 2;k ++)
                dp[i][j][0]  =( dp[i][j][0] + dp[i-1][j][k]) % mod;
            
            for(int k = 0;k <= 2;k ++)
                dp[i][1][0]  =( dp[i][1][0] + dp[i-1][0][k]) % mod;

            for(int j = 0;j <= 1;j ++)
            for(int k = 1;k <= 2;k ++)
                dp[i][j][k]  =( dp[i][j][k] + dp[i-1][j][k-1]) % mod;

        }
        int result = 0;
         for(int j = 0;j <= 1;j ++)
            for(int k = 0;k <= 2;k ++)
            result =( result+  dp[n][j][k] )% mod;
        return result;
    }
};
