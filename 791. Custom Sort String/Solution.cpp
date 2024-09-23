class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> memo;

        for(auto x: s)
        {
            memo[x]++;
        }
        string res ="";
        for(auto x: order)
        {
            if(memo[x] > 0)
            while(memo[x]--)
            res += x;
     
        }
        for(auto x: memo)
        {
            int counter = x.second;
            if(counter > 0)
            while(counter--)
            res += x.first;
        }

        return res;
    }
};
