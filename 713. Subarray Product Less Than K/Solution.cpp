class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int n = nums.size();
        int res = 0;
        int sum = 1;
        int i = 0;
        for(int j = 0;j < n;j++)
        {
            
            sum *=  nums[j];
            while(sum >= k && i <= j)
            {
                sum /= nums[i];
                i++;
            }

            res += j-i +1;
        }

        return res;
    }
};
