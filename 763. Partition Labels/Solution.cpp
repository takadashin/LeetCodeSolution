class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> memo;
        int count = 0, end = -1;

        for(int i = 0;i < n;i++)
        memo[s[i]] = i;
        vector<int> res;
        for(int i = 0;i < n;i++)
        {
            if(end <  memo[s[i]]) end = memo[s[i]];
            

            if(i == end) res.push_back(count+1),count = 0;
            else
            count++;
        }

        return res;
    }
};
