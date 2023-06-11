class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result  = to_string(nums[0]);
        if( nums.size() == 2)
        result += "/" + to_string(nums[1]);
        if( nums.size() > 2)
        {result += "/(";
        for(int i = 1; i < nums.size();i++)
        {
            result += to_string(nums[i]) + "/";
        }
        result.pop_back();
        result += ")";}
        return result;
    }
};
