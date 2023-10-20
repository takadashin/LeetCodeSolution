class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int k,res = 0 ;
        for(int i = 0;i < n-2;i++)
        {
            k = i+2;
            for(int j = i+1;j < n-1 && nums[i] != 0;j++)
            {
                while(k < n && nums[k] < nums[i] + nums[j])k++;
                res += k -j -1;
            }
        }
        return res;
    }
};
