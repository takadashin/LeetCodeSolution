class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int> tempmemo;
        vector<pair<int,int>> memo;
        for(int i = 0; i < profit.size();i++) 
        tempmemo[difficulty[i]] = max(profit[i], tempmemo[difficulty[i]]) ;
        for(auto x: tempmemo)
        memo.emplace_back(x.first,x.second);

        int maxprofit = 0;
 
        for(int i = 0; i < memo.size();i++)
        {
            if(maxprofit < memo[i].second) maxprofit = memo[i].second;
            else memo[i].second = maxprofit;

        }
        int res = 0;
        int temp = 0;
        for(auto x: worker)
        {
            temp = 0; // reset temp
            int left = 0, right = memo.size()-1;
            int target = -1;
            while(left <= right)
            {
                int mid = left + ( right - left)/2;
                if(memo[mid].first <= x)
                {
                    target = mid;
                    left = mid+1;

                }
                else
                {
                    right = mid-1;
                }
                

            }
            if(target != -1) res += memo[target].second;


           
        }
        return res;
        

    }
};
