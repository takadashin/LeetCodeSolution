class Solution {
public:

int kInversePairs(int n, int k) {
  
  
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    for (int N = 1; N <= n; ++N)
    {
        dp[N][0] = 1;
    }
    for (int N = 2; N <= n; ++N)
        for (int K = 1; K <= k; ++K) {
            dp[N][K] = (dp[N - 1][K] + dp[N][K - 1] ) % 1000000007;
            if (K >= N)
                dp[N][K] = (1000000007 + dp[N][K] - dp[N-1][K - N]) % 1000000007;
            //if (dp[N][K] <= 0) { dp[N][K] = 0; break; }
        }
    return dp[n][k];
}
};
