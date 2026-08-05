class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        int res = 0;
        for(int i = 1; i < n-1;i++)
        {
            int left = i-1, right = i+1;
            if(arr[left] < arr[i] && arr[i] > arr[right]) 
            {
                while(left >= 0 && arr[left] < arr[left+1])
                left--;
            
                while(right < n && arr[right - 1] > arr[right])
                    right++;
                res = max(res, right - left-1);
            }
            else
            continue;
            
            
        }

        return res;

        
    }
};
