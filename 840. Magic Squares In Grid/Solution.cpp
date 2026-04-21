class Solution {
public:

    bool isMagicSquares(vector<vector<int>>& grid, int r,int c )
    {
        int n = grid.size();
        int m = grid[0].size();
        // check if the number inside is from 1 to 9 without dup
        bool test[10] = {false};

        for(int  i = r-1; i <= r+1;i++ )
        for(int j = c-1; j <= c+1;j++ )
        {
            if(grid[i][j] <= 0 || grid[i][j]  > 9) return false;
            if(test[grid[i][j]]) return false;
            test[grid[i][j]] = true;
        }

        

        int topleft = grid[r-1][c-1];
        int topmid = grid[r-1][c];
        int topright = grid[r-1][c+1];
        int midleft = grid[r][c-1];
        int midmid = grid[r][c];
        int midright = grid[r][c+1];
        int bottomleft = grid[r+1][c-1];
        int bottommid = grid[r+1][c];
        int bottomright = grid[r+1][c+1];

        //next checkpoint is \/
        if((topleft + bottomright ) != (topright + bottomleft))  return false;

        int rowcount = topleft+topmid+topright;

        if(rowcount != (midleft + midmid + midright) || rowcount != (bottomleft + bottommid + bottomright)) return false;

        int colcount = (topleft + midleft + bottomleft);

        if(colcount != (topmid + midmid + bottommid) || rowcount != (topright + midright + bottomright)) return false;

        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        for(int i = 1; i < n-1;i++)
        for(int j = 1; j < m-1;j++)
        {
            if(isMagicSquares(grid,i,j)) res++;

        }

        return res;
        
    }
};
