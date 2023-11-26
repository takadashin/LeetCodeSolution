class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        int res = 0;
        vector<int> memo(n,1);

        for(int i = n-1;i >= 0;i--)
        {
            for(int j = i+1;j < n;j++)
            {
                if(pairs[i][1] < pairs[j][0]) memo[i] = max(memo[j]+1,memo[i]);
            }
            res = max(res,memo[i]);
        }

        return res;
    }
};
