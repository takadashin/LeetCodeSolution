class Solution {
public:

vector<vector<int>> dp;
    int btr_changecoin2(int amount, vector<int>& coins,int indexer, vector<vector<int>>& dp)
{
    if (amount == 0)
        return 1;
        else if (dp[amount][indexer] != -1) return dp[amount][indexer];
    else if (indexer >= coins.size()) return 0;
    else if(coins[indexer] > amount) 
        return dp[amount][indexer] =  btr_changecoin2(amount,coins,indexer+1,dp);

    
    return dp[amount][indexer] = btr_changecoin2(amount,coins,indexer+1,dp) + btr_changecoin2(amount-coins[indexer] ,coins,indexer,dp);
}
int change(int amount, vector<int>& coins) {

    vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
    return btr_changecoin2(amount, coins,0,dp);
}

};
