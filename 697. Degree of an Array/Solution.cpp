class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = 50000,max = 0;

        unordered_map<int,int> st,ss;

        for(int i = 0;i < nums.size();i++)
        {
            if(st[nums[i]] == 0) {
                ss[nums[i]] = i;
                st[nums[i]]++;
            }
            else
            {
                st[nums[i]]++;
                if(max < st[nums[i]])
                {
                    max = st[nums[i]];
                    res = i - ss[nums[i]] + 1;
                }
                else if(max == st[nums[i]])
                {
                    res = min(res,i - ss[nums[i]] + 1);
                }

            }
        }
         return res == 50000 ? 1 : res;
    }
   
};
