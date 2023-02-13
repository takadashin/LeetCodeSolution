class Solution {
public:

    void backtracking_find(vector<int>& nums,set<vector<int>>& ans,vector<int>& tmp,int idx)
    {
        //base case
        if(idx >= nums.size())
        {if(tmp.size() > 1)
        ans.insert(tmp);
        return;}

        if( tmp.size() == 0 || nums[idx] >= tmp[tmp.size()-1])
        {
            tmp.push_back(nums[idx]);
            backtracking_find(nums,ans,tmp,idx+1);
            tmp.pop_back();
        }
        backtracking_find(nums,ans,tmp,idx+1);
        


    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> tmp;

        backtracking_find(nums,ans,tmp,0);
        vector<vector<int>> ans2;
        for(auto x: ans)
            ans2.push_back(x);

        return ans2;
    }
};
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
