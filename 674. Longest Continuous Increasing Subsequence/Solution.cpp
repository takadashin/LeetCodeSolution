class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int counter = 0,res = 0;
        int temp = INT_MAX;
        for(int i = 0;i < nums.size();i++)
        {
            if(temp >= nums[i])
                {res = max(res,counter),counter = 1;}
            else
                counter++;
            temp = nums[i];
        }
        res = max(res,counter);
        return res;
    }
};
