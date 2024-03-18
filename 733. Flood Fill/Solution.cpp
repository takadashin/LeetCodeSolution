class Solution {
public:

    void dfs_fill(int r,int c,int color,vector<vector<int>>& image,int oldcolor)
    {
        if(color == oldcolor) return;
        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size())
        return;
        if(image[r][c] != oldcolor)
        return;

        image[r][c] = color;
        dfs_fill(r + 1,c, color, image,oldcolor);
        dfs_fill(r,c + 1, color, image,oldcolor);
        dfs_fill(r - 1,c, color, image,oldcolor);
        dfs_fill(r,c - 1, color, image,oldcolor);



    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         dfs_fill(sr,sc, color, image,image[sr][sc]);
         return image;


    }
};
