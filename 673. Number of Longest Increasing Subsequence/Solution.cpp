class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> lis(n, 1);
    vector<int> ms(n, 1);
    int maxlen = INT_MIN,maxin = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                if (lis[j] + 1 > lis[i]) // trường hợp căn bản, giá trị num i > j và lis j++ lai bằng lis i
                {
                    lis[i] = lis[j] + 1;
                    ms[i] = ms[j];
                }
                else if(lis[i] == lis[j]+1) // if number is increase but lis của i bị hục 1 đơn vị, chỉ có thể là tồn tại 1 sequence khác
                    ms[i] += ms[j]; // cộng dồn với số sequence của index j vào i
        }
        }

        for (int i = 0; i < n; i++)if(maxlen < lis[i]) // phải reset i = 0 để đếm lại số lượng
        {
            maxlen = lis[i];
            maxin =  ms[i];
        }
        else if(maxlen == lis[i])
         maxin +=  ms[i];
        return maxin;
    }

    

};
