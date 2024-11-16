class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> memo(102,vector<double>(102,0));
        memo[0][0] = poured;
        for(int r= 0; r < 101;r++)
        for(int c =0; c <= r; c++)
        {
            if(memo[r][c] > 1)
            {
                double ov = (memo[r][c] - 1) / 2;
                memo[r+1][c] += ov;
                memo[r+1][c+1] += ov;
            }
        }

        if(memo[query_row][query_glass] > 1)
        return 1;
        else return memo[query_row][query_glass] ;
    }
};
