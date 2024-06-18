class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() == 0) return 0;

        int maxn = 0,res = 0;
        for(int  i = 0;i < arr.size();i++)
        {
            maxn = max(maxn,arr[i]);
            if(maxn == i) res++;

        }

        return res;
    }
};
