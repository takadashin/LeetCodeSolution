class Solution {
public:
    int counthelper(vector<vector<int>>& grid,int r,int c)
    {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;
        else
        {
        int count = 1;
        grid[r][c] = 0;
        count += counthelper(grid,r-1,c) + counthelper(grid,r,c-1) + counthelper(grid,r+1,c) + counthelper(grid,r,c+1);
        return count;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    res = max(res, counthelper(grid,i,j));
                }
            }
        }

        return res;
    }
};
