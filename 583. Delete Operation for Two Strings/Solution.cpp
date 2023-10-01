class Solution {
public:
    
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
        memo[i][0] = i;

    for (int i = 0; i <= n; i++)
        memo[0][i] = i;


    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {

            if (word1[i - 1] == word2[j - 1])
                memo[i][j] = memo[i - 1][j - 1]; 
            else
                memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + 1;
        }

    return memo[m][n];
}
};
