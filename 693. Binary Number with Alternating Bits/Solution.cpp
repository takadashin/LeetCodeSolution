class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool test;

        test = (n & 1);
       
        while(n)
        {
            n = n >> 1;
            if(test == (n & 1) ) return false;
            test = (n & 1);
        }

        return true;

        
    }
};
