class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int,int>>> memo(26);

        for(int i = 0;i < words.size();i++)
        {
            int pos = words[i][0] - 'a';
            memo[pos].push_back({i,0});
        }

        int res = 0;
        for(auto x: s)
        {
            auto tm = memo[x-'a'];
            memo[x-'a'].clear();
            for(auto o : tm)
            {
                o.second++;
                if(o.second == words[o.first].size())res++;
                else
                memo[words[o.first][o.second]- 'a'].push_back({o.first,o.second});
            }
        }
        return res;
    }
};
