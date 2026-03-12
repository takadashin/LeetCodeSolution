class Solution {
public:
    

string pushDominoes(string dominoes) {
    // 4 cases
    // R......R or L......L will become RRRRRRR or LLLLLLLL
    // L......R become LLLLRRRR or LLL.RRR
    // R......R keeps the same state

    int n = dominoes.size();
    if(n == 1) return dominoes;
    string res = dominoes;
    int i = 0, j = 0;
    while (i < n)
    {
        if (dominoes[i] != '.')
        {
            j = i+1;
            while (j < n && dominoes[j] == '.')j++;
            if (j == n) break;
            if (dominoes[i] == dominoes[j])
                for (int x = i; x <= j; x++) res[x] = res[i];
            else if (dominoes[i] == 'R' && dominoes[j] == 'L')
                for (int x = i+1, y = j-1; x < y; x++, y--) {
                    res[x] = dominoes[i]; 
                    res[y] = dominoes[j];
                }


            i = j;
        }
        else
            i++;
        

        

    }
    for (i = 0;  i < n; i++)
{
    if (res[i] != '.') break;
}
if (i < n && res[i] == 'L')
    while (i - 1 >= 0)
    {
        res[i - 1] = res[i];
        i--;
    }

for (i = n - 1; i >= 0; i--)
{
    if (res[i] != '.') break;
}
if (i >=0 && res[i ] == 'R')
    while (i < n)
    {
        res[i + 1] = res[i];
        i++;
    }


    return res;

}
};
