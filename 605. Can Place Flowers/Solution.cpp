class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();

        if(s == 1 && flowerbed[0] == 0) return true;

        if(flowerbed[0] == 0 && flowerbed[1] == 0){ n--; flowerbed[0] = 1;}

        if(flowerbed[s-1] == 0 && flowerbed[s-2] == 0){n--;flowerbed[s-1] = 1;}

        
        

        if(s > 2)
        {
            for(int i = 1;i < s-1;i++)
            {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {n--;i++;}
            }
        }

        return n <= 0;
    }
};
