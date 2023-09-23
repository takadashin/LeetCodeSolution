class Solution {
public:
    int mod = pow(10,9) + 7;
    int whatever(int r,int c,int move,vector<vector<vector<int>>>& memo3d)
    {
        if(r < 0 || r >= (memo3d[0].size()-1) ||  c < 0 || c >= (memo3d[0][0].size() - 1) ) return 1;
        if(move == (memo3d.size()-1)) return  0;
        if(memo3d[move][r][c] != -1) 
        return memo3d[move][r][c];

        int res = whatever(r + 1,c,move +1,memo3d) % mod;
        res = (res + whatever(r ,c + 1,move +1,memo3d)) % mod;
        res = (res + whatever(r -1 ,c ,move +1,memo3d)) % mod;
        res = (res + whatever(r ,c - 1,move +1,memo3d)) % mod;
        memo3d[move][r][c] = res;
        return res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo3d(maxMove+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return   whatever(startRow,startColumn,0,memo3d);
       

    }
};
