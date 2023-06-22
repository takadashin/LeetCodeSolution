class Solution {
public:
    
int longestOnes(vector<int>& nums, int k) {
    int count0 = 0;
    int head = 0;
    int res = 0;
    for(int tail = 0; tail < nums.size();tail++)
    {
        if(nums[tail] == 0)
        count0++;

        while(count0 > k)
        {
            if(nums[head] == 0)
            count0--;

            head++;
        }
        res = max(res,tail-head+1);

    }
    return res;
}
};
