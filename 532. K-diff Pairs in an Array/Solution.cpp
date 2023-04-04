class Solution {
public:

int findPairs(vector<int>& nums, int k) {
    int n =  nums.size();
    sort(nums.begin(), nums.end());
    int counter = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (i == j || (j < n && nums[j] - nums[i] < k))
            j++;
        if (j < n && nums[j] - nums[i] == k)
        {
            for (; j < nums.size(); j++)
            {
                if (nums[j] != nums[j - 1])
                    break;
            }
            counter++;
        }
        while (i < j && i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }

    return counter;
}
};
