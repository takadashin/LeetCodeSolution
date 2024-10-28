class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(), l = -1,r = -1;
        int res = 0;
        for(int i = 0 ;i < n;i++)
        {
            if(nums[i] > right) l = i;// left go slower than right
            if(nums[i] >= left) r = i;
          
        }

        return res;
    }
};
