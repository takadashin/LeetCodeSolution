class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m+1,vector<int>(n+1,0));

        for(int i = m;i >= 0 ; i--)
            memo[i][n] = m-i;
        for(int j = n;j >= 0 ; j--)
            memo[m][j] = n-j;
        

       
       
        m--;
        n--;
        while(m >= 0 && n >= 0)
        {
            for(int i = m;i >= 0 ; i--)
            {
                if(word1[i] == word2[n])
                    memo[i][n] = memo[i+1][n+1];
                else
                {
                    memo[i][n] = min(memo[i+1][n],memo[i][n+1]);
                    memo[i][n] = min(memo[i][n],memo[i+1][n+1]);
                    memo[i][n]++;
                }
            }
            for(int j = n;j >= 0 ; j--)
            { 
                if(word1[m] == word2[j])
                    memo[m][j] = memo[m+1][j+1];
                else
                {
                    memo[m][j] = min(memo[m+1][j],memo[m][j+1]);
                    memo[m][j] = min(memo[m][j],memo[m+1][j+1]);
                    memo[m][j]++;
                }
            }

            
            m--;
            n--;
           
        }
        return  memo[0][0];

    }
};
