class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res = 0,maxres = 0,head = 0;
        for(int i = 0; i < k;i++)
            res += nums[i];


        maxres = res;
        int tail = k-1;
        while(tail +1 < nums.size())
        {
            tail++;
            res = res +nums[tail] - nums[head];
            maxres = max(res,maxres);
            head++;
        }
        return (double) maxres/k;
    }
};
