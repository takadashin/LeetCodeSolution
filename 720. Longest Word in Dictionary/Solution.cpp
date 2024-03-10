class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());

        set<string> memo;
        string res;
        for(auto x: words)
        {
            if(x.size() == 1 || memo.count(x.substr(0,x.size()-1)))
            {
                res = res.size() < x.size() ?x:res;
                memo.insert(x);
        
            }
        }

        return res;
    }
};
