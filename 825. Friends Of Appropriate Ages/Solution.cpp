class Solution {
public:
bool canbefriend(int age1,int age2)
{ return !(age2 <=( 0.5 * age1 + 7) || age2 > age1 || (age2 > 100 && age1 < 100));}
    int numFriendRequests(vector<int>& ages) {
        vector<int> memo(121,0);
        int res = 0;
        for(auto x: ages) memo[x]++;

        for(int i = 1;i  < 121;i++)
        {
            if(memo[i] == 0) continue;
            for(int j = 1; j < 121;j++)
            {
                if(memo[j] == 0) continue;
                if(canbefriend(i,j))
                {res += (memo[i] * memo[j]);

                if(i == j)
                res -= memo[j] ;}
            }
        }
        return res;
    }
    
};
