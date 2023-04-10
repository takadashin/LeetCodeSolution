class Solution {
public:

  
int findnondup(vector<int>& nums, int low, int high)
{
    
    int unique = ((high - low)+1) / 2 + 1;

    int mid = low + ((high - low) / 2);
    if (low == high) return nums[mid];
    if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        return nums[mid];
    else if (nums[mid] == nums[mid - 1])
    {
        if (unique % 2 == 1)return findnondup(nums, low, mid);
        else return findnondup(nums, mid + 1, high);
    }
    else
    {
        if (unique % 2 == 1)return findnondup(nums, mid , high);
        else return findnondup(nums, low, mid - 1);
    }
}

    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
        return nums[0];
        // how many number could existed in this array
        //if size is 1, then 1, size is 3 then 2, size is 5 then 3 
        //formular is nums.size()/2 +1

      
        return findnondup(nums,0,nums.size()-1);
    }
};
