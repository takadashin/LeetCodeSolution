class Solution {
public:
    bool validcheck(int r,int c,int n)
    {
        if(r >= 0 && r < n && c >= 0 && c < n) return true;
        return false;

    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> memop(n,vector<double>(n,0));
        vector<vector<double>> memoc(n,vector<double>(n,0));
        vector<vector<int>> move{{1,2},{2,1},{-1,-2},{-2,-1},{-1,2},{2,-1},{1,-2},{-2,1}};
        memop[row][column] = 1;
        double res = 1;
        while(k--)
        {
            res = 0;
            for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
            {
                if(memop[i][j] > 0){
                    for(auto x: move)
                    if(validcheck(i + x[0],j+x[1],n))
                        memoc[i + x[0]][j+x[1]] += memop[i][j]/8,res +=  memop[i][j]/8;


                }
            }

            memop = memoc;
            fill(memoc.begin(),memoc.end(),vector<double>(n,0));
        }
        return res;
    }
};
