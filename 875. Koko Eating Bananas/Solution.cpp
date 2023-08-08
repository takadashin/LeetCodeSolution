class Solution {
public:
   int bin_helper(vector<int>& piles,int low,int high,int h)
    {
        if(low  == high) return low;
 
        int k = low + (high - low) /2;

        int counter = 0;
        for(auto x: piles)
        { 
            counter += x / k; 
            counter += x % k? 1:0;
        }

        
        if(counter <= h)
        return bin_helper(piles,low,k,h);
        else
        return bin_helper(piles,k+1,high,h);

    }
    int minEatingSpeed(vector<int>& piles, int h) {

       
        sort(piles.begin(),piles.end());
        return bin_helper(piles,1,piles[piles.size()-1],h);
    }
};
