class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> counter;
        int ans = 0;
        for(auto x: answers)
            counter[x]++;

        for(auto x: counter)
        {
            int temp =  x.second / (x.first+1);
            int remain =  x.second % (x.first+1);
            ans += temp * (x.first+1) + (remain ? x.first+1 : 0);
        }
            


        return ans;
    }
};
