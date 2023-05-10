class Solution {
public:
    int dp[100][100][100]  = {};
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp,0,sizeof(dp));
        return helper(boxes,0,n-1,0);
    }

    int helper(vector<int>& boxes,int i,int j,int k)
    {
        if(i > j) return 0;
        if(dp[i][j][k] != 0) return dp[i][j][k] ;

        int res = (k+1)*(k+1) + helper(boxes,i+1,j,0);

         
        for(int m = i+1;m <=j;m++)
        if(boxes[m] == boxes[i] ) res = max(res, helper(boxes,i+1,m-1,0)+ helper(boxes,m,j,k+1));
        return dp[i][j][k]  = res;
    }
};
