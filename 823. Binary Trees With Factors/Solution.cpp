class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map<int,long> memo;
        long mod = pow(10,9) + 7;
     
        for(auto x: arr)
        memo[x] = 1;

        int res= 0;
        for(int i = 0;i < n;i++){
        for(int j = 0; j < i;j++)
        {
            if(arr[i] % arr[j] == 0)
            if(memo.count(arr[i] / arr[j] ) > 0)
            {
                memo[arr[i]] = (memo[arr[i]] + ( memo[arr[i] / arr[j]] * memo[arr[j]]) ) % mod;
            }
        }
        res = (res + memo[arr[i]] ) % mod;
        }

        return res;
        
    }
};
