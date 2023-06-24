class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        //vector<int> res(n,0);
        int temp = 0;
        int maxn = 0;
        for(int i = 1;i <= n;i++)
        {
            temp += gain[i-1] ;

            maxn = max(maxn, temp);
        }

        return maxn;
    }
};
