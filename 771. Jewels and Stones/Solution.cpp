class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> st;

        for(auto x:jewels) st.insert(x);
        int res = 0;
        for(auto x: stones)
        if(st.count(x) > 0) res++;

        return res;
    }
};
