class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX,y = INT_MAX;

        for(auto t: nums)
        {
            if(t <= x) x = t;
            else if(t <= y) y = t;
            else return true;
        }

        return false;
    }
};
