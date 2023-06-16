class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        res.push_back(1);
       

        for(int i = 1; i < nums.size();i++)
        {
            res.push_back(nums[i-1] * res.back()) ;
        }
        int tmp = 1;
        for(int i =  nums.size() - 2; i >= 0;i--)
        {
            tmp *= nums[i+1] ;
            res[i] *= tmp ;
        }



        return res;
    }
};
