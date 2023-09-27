class Solution {
public:
   

 int findUnsortedSubarray(vector<int>& nums) {
     // scanning method
    int n = nums.size();
     vector<int> forw(n,0),bac(n,0);

     int minn = INT_MAX,maxn = INT_MIN;

     for(int i = n-1;i >= 0;i--)
     {
         minn = min(minn,nums[i]);
         forw[i] = minn;
     }
     for(int i = 0;i < n;i ++)
     {
         maxn = max(maxn,nums[i]);
         bac[i] = maxn;
     }
    int start = 0, end = n- 1;
    while(start < n && nums[start] == forw[start])
    start ++;
    while(end > start && nums[end] == bac[end])
    end--;
    return end - start +1;
 }
};
