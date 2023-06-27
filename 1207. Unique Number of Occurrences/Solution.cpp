class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> chk_arr;
        set<int> dup;
        for(auto x:arr)
        {
            chk_arr[x]++;
        }
        for(auto x:chk_arr)
        {
            if(dup.count(x.second) > 0) return false;
            else
            dup.insert(x.second);
        }

        return true;


    }
};
