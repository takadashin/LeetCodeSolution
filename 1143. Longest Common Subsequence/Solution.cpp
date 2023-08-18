class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        vector<vector<int>> memo(m,vector<int>(n));
        for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
                 memo[i][j] = ( (text1[i] == text2[j]) ? ( i - 1 >= 0 && j - 1 >= 0?  memo[i - 1][j-1] +1: 1) : max( (i - 1 >= 0 ? memo[i - 1][j] : 0), (j - 1 >= 0 ? memo[i][j - 1] : 0)) );
        return memo[m-1][n-1];


        
    }
};
