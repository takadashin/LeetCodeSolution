class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> ans;
    
    vector<pair<int,int>> memo; // store the value and index of that value
    for (int i = 0; i < nums.size(); i++)
        for (auto x : nums[i])
            memo.push_back({ x,i });

    sort(memo.begin(), memo.end()); // sort based on the first value 
    unordered_map<int, int> mp; // store index and number that belongs in that index | mp[index,counter]
    int i = 0, k = 0;//  i will be the tail and k will be the first counter alerts that its reach the condition of all value of all index is bt i and j

    for (int j = 0; j < memo.size(); j++) // j is the head that keeps collecting value
    {
        if (! mp[memo[j].second]++ ) k++; // we increase the counter in map to know how many value of index currenct reside within i and j 

        if (k == nums.size()) // reach the alert k will stop counting after this
        {
            while (mp[memo[i].second] > 1) // scan through the mp just to get rid of current i if counter is more than 1
            {
                mp[memo[i].second]--;
                i++;
            }

            if (ans.empty() || ans[1] - ans[0] > memo[j].first - memo[i].first) // only reach these conditions to register to ans
            {
                ans =  vector<int>{ memo[i].first ,memo[j].first };
            }
        }
    }
    return ans;
}
};
