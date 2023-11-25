class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int missing = 1;
        int dup  = 0;
        if(nums[0] == missing) missing++;
        for(int i = 1;i < nums.size();i++)
        {

            if(nums[i] == missing) missing++;
            if(nums[i] == nums[i-1]) {dup = nums[i];}
        }

        return {dup,missing};

    }
};
