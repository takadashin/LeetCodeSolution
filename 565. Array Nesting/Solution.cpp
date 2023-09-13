class Solution {
public:

     int countdfs(vector<int>& nums,int indexer)
    {
        if(indexer == -1 || nums[indexer] == -1) return 0;
        int tmp = nums[indexer] ;
        nums[indexer] = -1;
        return countdfs(nums,tmp) +1 ;
    }
    int arrayNesting(vector<int>& nums) {
        int res = 0;

        for(int i = 0;i < nums.size();i++)
            if(nums[i] != -1)
                res = max(res,countdfs(nums,i));

        return res;
    }
};
