class Solution {
public:
   void bk_findTargetSumWays(vector<int>& nums, int& target, int idx, int cursum,int& counter)
{
    if (idx >= nums.size())
    {
        if (cursum == target)
            counter++;

        return;
    }

    
    bk_findTargetSumWays(nums, target, idx + 1, cursum + nums[idx], counter);
    bk_findTargetSumWays(nums, target, idx + 1, cursum - nums[idx], counter);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int cursum = 0,counter = 0;
    bk_findTargetSumWays(nums, target, 0 , 0, counter);
    return counter;
}
};
