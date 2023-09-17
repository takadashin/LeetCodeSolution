class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int tmp = -1;
        int counter = 0;
        for(auto x: candyType)
        {
            if(tmp != x)
            {
                tmp = x;
                counter++;
            }
        }

        int allow = candyType.size() /2;

        return min(allow,counter);
    }
};
