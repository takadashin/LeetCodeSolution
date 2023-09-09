class Solution {
public:
int subarraySum(vector<int>& nums, int k) {

    int res = 0;
    unordered_map<int,int> visited;
    visited[0]++;
    int col_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        col_sum += nums[i];
        
        if (visited.count(col_sum - k))
            res +=  visited[col_sum - k];
        visited[col_sum]++;


    }


    return res;
}
};
