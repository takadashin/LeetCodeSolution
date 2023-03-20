class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> checker;
        checker[0] = -1;
        int sumt = 0;
        for(int i = 0;i < nums.size();i++)
        {
            sumt = (sumt + nums[i]) % k;
            if(checker.find(sumt) != checker.end())
            {
                if(i-checker[sumt] > 1)
                return true;
                else continue;
            }
            checker[sumt] = i;
        }

        return false;
    }
};
