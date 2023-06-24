class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int head = 0,count0 = 0,res = 0;
        for(int t = 0;t < nums.size();t++)
        {
            if(nums[t] ==0)
            count0++;

            while(count0 > 1)
            {
                if(nums[head] == 0)
                count0--;

                head++;
            }
            res= max(res,t-head);
        }
        return res;
    }
};
