class Solution {
public:

    bool binary_sqrt(long low,long high, int x)
    {
        if(low > high) return false;
         
         long mid = low + (high - low)/2;

         if(mid * mid == x)
         return true;
         else if(mid * mid > x)
         return binary_sqrt(low,mid-1,x);
         else
         return binary_sqrt(mid+1,high,x);
    }
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        for(long i = 0;i*i < c;i++)
        {
            long x = c - i*i;
            if(binary_sqrt(0,x,x)) return true;
        }
        return false;
    }
};
