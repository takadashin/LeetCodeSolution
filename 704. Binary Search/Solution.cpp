class Solution {
public:


    int binary_search(vector<int>& nums, int& target,int low,int high)
    {
        
        if(low > high) {
            
            return -1;}

        int mid = low + ((high - low) /2);
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target)
        return binary_search(nums,target,low,mid-1);
        else
        return binary_search(nums,target,mid+1,high);
    }

    int search(vector<int>& nums, int target) {
        return binary_search(nums,target,0,nums.size()-1);
    }
};
