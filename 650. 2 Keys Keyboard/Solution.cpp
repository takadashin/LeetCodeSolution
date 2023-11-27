class Solution {
public:
    int minSteps(int n) {
    vector<int> memo(n + 1, 0);
    if (n >= 2) memo[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        memo[i] = i;
        for(int j = i-1;j > 1;j--)
        {
            if (i % j == 0){ memo[i] =  memo[j] + i/j;
            break;}
        }



    }
    return memo[n];
}
};
