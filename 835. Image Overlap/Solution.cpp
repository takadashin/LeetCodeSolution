class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<int> la,lb;
        int res = 0;
        unordered_map<int,int> count;

        for(int i = 0 ;i < n*n;i++)
        {
            if(img1[i/n][i%n] == 1) la.push_back((i/n)* 100 + (i%n));
            if(img2[i/n][i%n] == 1) lb.push_back((i/n)* 100 + (i%n));
        }
        for(auto x: la) for(auto y: lb) count[x-y]++;
        for(auto z: count)
            res = max(res,z.second);

        return res;
    }
};
