class Solution {
public:
    
int pivotIndex(vector<int>& nums) {

   
    int n = nums.size();
    vector<int> res(n, 0);
    int tmp = 0;
    int resu = -1;
    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] + nums[i - 1];
    }
    if (res[n - 1] == 0)  resu = n-1;
    for (int i = n - 2; i >= 0; i--)
    {
        tmp +=  nums[i + 1];

        res[i] -= tmp;
        if (res[i] == 0) resu = i;
    }

    
    return resu;


}
};
