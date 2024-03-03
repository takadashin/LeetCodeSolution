class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n;i++) memo[i][0] = memo[i-1][0] + s1[i-1];
        for(int i = 1; i <= m;i++) memo[0][i] = memo[0][i-1] + s2[i-1];

        for(int i = 1; i <= n;i++)
        for(int j = 1; j <= m;j++)
        {
            if(s1[i-1]== s2[j-1]) memo[i][j] = memo[i-1][j-1] ;
            else
            memo[i][j] = min( memo[i-1][j] + s1[i-1] , memo[i][j-1] + s2[j-1]  );
        }
        return memo[n][m];
    }
};
