class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        vector<int> row(grid.size(),0) , col(grid[0].size(),0);

        for(int i = 0; i < row.size();i++)
        
            for(int j = 0; j < col.size();j++)
                row[i] = max(row[i], grid[i][j]),col[j] = max(col[j] , grid[i][j]);;
                

    





        int res = 0;
        for(int i = 0; i < row.size();i++)
            for(int j = 0; j < col.size();j++)
                res +=( min(row[i],col[j]) - grid[i][j]);


        return res;
    }
};
