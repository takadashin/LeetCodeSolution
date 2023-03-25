class Solution {
public:

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    int maxlen = 0;
    unordered_map<int, int> checker;
    checker[0] = -1;
    int sumter = 0;
    for (int i = 0; i < n; i++)
    {
        sumter += (nums[i] == 1 ? 1 : -1);
        if(checker.find(sumter) == checker.end())
        checker[sumter] = i;
        else
        maxlen = max(maxlen, i - checker[sumter]);


    }
    return (maxlen);
}
};
