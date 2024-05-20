class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n,vector<int>(n,1));

        for(auto x: mines)
        {
            matrix[x[0]][x[1]] =  0;
        }

        vector<vector<int>> left(n,vector<int>(n,0));
        vector<vector<int>> right(n,vector<int>(n,0));
        vector<vector<int>> top(n,vector<int>(n,0));
        vector<vector<int>> bottom(n,vector<int>(n,0));
        for(int i = 0;i < n;i++)
        for(int j = 0; j < n;j++)
        {
            if(matrix[i][j] == 1)
            {
                left[i][j] = (i > 0 ? left[i-1][j] + 1 :1 );
                top[i][j] = (j > 0 ? top[i][j-1] + 1 : 1 );
            }
        }

        for(int i = n-1; i >= 0; i--)
        for(int j = n-1; j >= 0; j--)
        {
            if(matrix[i][j] == 1)
            {
                right[i][j] = (i  < n -1   ? right[i+1][j] + 1 :1 );
                bottom[i][j] = (j  < n -1  ? bottom[i][j+1] + 1 : 1 );
            }
        }
        int mintotal,res = 0;
        for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            mintotal = min({left[i][j],right[i][j],top[i][j],bottom[i][j]});
            res = max(res,mintotal);
        }
        }
        return res;
    }
};
