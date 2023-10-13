class Solution {
public:
    
int findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0, j = 0, res = 0;
    while (j < nums.size())
    {
        if (nums[j] <= nums[i] + 1) j++;
        
        while (j < nums.size() && nums[j] - 1 > nums[i])i++;

        if (j < nums.size() && nums[j] != nums[i])
            res = max(res, j - i + 1);

    }
    return res;
}
};
