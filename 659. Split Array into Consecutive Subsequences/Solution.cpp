class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>  ck,st;

        for(auto x: nums)
            ck[x]++;
        
        //pass 1
        int p1 = 0;
        for(auto x: nums)
        {
            if(!ck[x]) continue;
            ck[x]--;

            if(st[x-1] > 0)
            {
                st[x-1] --;
                st[x]++;
            }
            else if(ck[x+1] > 0 && ck[x+2] > 0)
            {
                ck[x+1]--;
                ck[x+2]--;
                st[x+2]++;
            }
            else return false;

            

        }
        return true;
        
    }
};
