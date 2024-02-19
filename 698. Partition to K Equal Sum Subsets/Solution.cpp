class Solution {
public:
    bool bk_can(vector<int>& nums, int k,int i,int target,int curr ,  vector<bool>& visited)
    {
        if(i >= nums.size()){
      
            return false;
        }
        if(k == 1) return true;
    
        if(curr == target) return bk_can(nums,k-1,0,target,0,visited );
        for(int j = i;j < nums.size();j++)
        {
            if(visited[j] || curr + nums[j] > target) continue;
            visited[j] = true;
            if(bk_can(nums,k,j+1,target,curr + nums[j],visited )) return true;
            visited[j] = false;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sumt = 0;

        for(int x: nums)
            sumt += x;

        
        if(sumt % k != 0 || nums.size() < k) return false;
       
        sort(nums.begin(),nums.end(),greater<int>());
        vector<bool> visited(nums.size(), false);
        return bk_can(nums,k,0,sumt / k,0,visited );

    }
};
