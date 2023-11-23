class Solution {
public:

    int buyall(vector<int>& price, vector<int>& needs)
    {

        int res = 0;
        for(int i=0;i <  needs.size();i++) res += (price[i] * needs[i]);
        return res;
    }

    int helper_so(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int indexer)   
    {
        int res = buyall(price,needs);
        int n = price.size();
        for(int i=indexer;i < special.size();i++)
        {
            vector<int> newneed;

            for(int j=0;j < n;j++)
            {
                if(needs[j] < special[i][j])
                {
                    newneed.clear();
                    break;
                }
                newneed.push_back(needs[j] - special[i][j]);
                
            }
            if(!newneed.empty())
            res = min(res,special[i][n] + helper_so(price,special,newneed,i));
        }

        return res;

    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = helper_so(price,special,needs,0);
        return res;    
    }
};
