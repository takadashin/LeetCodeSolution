class Solution {
public:
    double memo[200][200];
    double operate(int a, int b)
    {
        if(a <= 0 && b <= 0) return 0.5;
        else if(a<= 0) return 1;
        else if(b <= 0) return 0;
        else
        {
            if(memo[a][b] != 0 ) return memo[a][b];
            else{
            memo[a][b] = 0.25 * (operate(a - 4,b) + operate(a-3,b - 1) + operate(a-2,b - 2)+ operate(a-1,b - 3));
            return memo[a][b];}
        }
    }
    double soupServings(int n) {
        if(n >=  4800) return 1;
        else
        return operate((n +24) / 25,(n +24) / 25);
    }
};
