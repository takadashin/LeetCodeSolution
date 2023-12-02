class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> res(26,0);
        for(auto t: moves)
            res[t-'A']++;
        return res['U'-'A'] == res['D'-'A'] && res['L'-'A'] ==  res['R'-'A'];
        
    }
};
