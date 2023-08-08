class Solution {
public:

    int tri_memo(int n, vector<int>& memo) {
       if(n == 0) return 0;
        else if(n ==  1) return 1;
        else if(n == 2) return 1;
        else if(memo[n] != -1) return memo[n];
        else{
            memo[n] = tri_memo(n-1,memo) + tri_memo(n-2,memo) + tri_memo(n-3,memo);
            return  memo[n] ;
            }
    }
    int tribonacci(int n) {
        vector<int> memo(38,-1);
        memo[0] = 0;memo[1] = 1;memo[2] = 1;
        return tri_memo(n,memo);


    }
};
