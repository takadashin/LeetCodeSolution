class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // now to check how much i reemember 

        //3 edge cases
        if( k == 0 ) return 1;
        if(n >= k + maxPts - 1) return 1;
        if( n < 0) return 0;

        vector<double> dp(n+1,0);
        dp[0] = 1;

        double maxSum = 0;
        for(int i = 1; i <= n;i++)
        {
            if( i <= k) maxSum += dp[i-1];
            if( i  - maxPts > 0 && i - maxPts -1 < k ) maxSum -= dp[i - maxPts -1];

            dp[i] = maxSum / maxPts;
        }

        double result = 0;
        for(int  i = k;i <= n;i++) 
        result += dp[i];

        return result;


    }
};
