class Solution {
public:

  
    int arrayNesting(vector<int>& nums) {
        int res = 0,counter = 0;;
        int tmp = 0,tmp2 = 0;

        for(int i = 0;i < nums.size();i++)
        {
            tmp = i;
            counter = 0;
            while(nums[tmp] != -1 )
            {
                counter++;
                tmp2 = tmp;
                tmp = nums[tmp];
                nums[tmp2] = -1;
            }
            res = max(res,counter);
        }

        return res;
    }
};
