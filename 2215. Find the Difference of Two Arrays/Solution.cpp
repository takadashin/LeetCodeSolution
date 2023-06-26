class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans,ans2;
        vector<int> res1, res2;
        for(auto x: nums1)
        ans.insert(x);
        for(auto x: nums2)
        {
            if(ans.count(x) ==  0) 
            {res2.push_back(x),ans.insert(x);};
            ans2.insert(x);
        }
        for(auto x: nums1)
        {
            if(ans2.count(x) ==  0) 
            {res1.push_back(x),
            ans2.insert(x);}
          
        }
        return {res1,res2};
    }
};
