class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        char cur = ' ';

        int index = 0,tempindex = 0;
        vector<vector<int>> res;
        for(auto x: s)
        {
            if(cur != x){
                if(index - tempindex >= 3) {
                    res.push_back({tempindex,index - 1});
                }
                cur = x;
                tempindex = index;
            }
            index++;
        }

         if(index - tempindex >= 3) {
                    res.push_back({tempindex,index - 1});
                }

        return res;
    }
};
