class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i = 0,j = nums.size()-1;
        int res = 0;
        sort(nums.begin(),nums.end());
        while(i < j)
        {
            if(nums[i] + nums[j] < k ) i++;
            else if(nums[i] + nums[j] > k ) j--;
            else
            {
                cout << nums[i] << ":" << nums[j] << endl;
                res++;
                 i++;
                 j--;
            }
            
        }
        return res;
    }
};
