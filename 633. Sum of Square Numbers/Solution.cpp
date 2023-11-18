class Solution {
public:

    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        for(long i = 0;i*i < c;i++)
        {
            double j = sqrt(c-i*i);
            if(j == (long) j) return true;
        }
        return false;
    }
};
