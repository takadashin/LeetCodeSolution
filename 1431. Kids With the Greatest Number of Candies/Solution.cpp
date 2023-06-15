class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxnum = candies[0];

        for(auto x: candies)
        maxnum = max(maxnum,x);
        vector<bool> res;
        for(auto x: candies)
        {
            res.push_back( (x+extraCandies >= maxnum) );
        }

        return res;

    }
};
