class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = abs( target[0]) + abs( target[1]);

        for(auto x: ghosts)
        {
            if(abs(x[0] - target[0]) + abs(x[1] - target[1]) <= dis) return false;
        }
        return true;
    }
};
