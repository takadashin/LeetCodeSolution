class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN,sell = 0;

        for(auto x: prices)
        {
            buy = max(buy,sell-x);
            sell = max(sell, x + buy -fee);
        }
        return sell;
    }
};
