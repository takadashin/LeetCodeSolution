class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> memo(n, INT_MAX);
        memo[src] = 0;
        for(int tmp = 0;tmp <= k;tmp++)
        {
            vector<int> tme(memo);
            for(auto x: flights)
            {
                if(memo[x[0]] != INT_MAX)
                {
                    tme[x[1]] = min(tme[x[1]], x[2] + memo[x[0]]);

                }
            }
            memo = tme;
        }
        return memo[dst] == INT_MAX ? -1: memo[dst];
    }

    
};
