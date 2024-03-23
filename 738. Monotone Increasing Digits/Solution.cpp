class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);

        n =  s.size();
        int ci = n;
        for(int i = n-1;i > 0;i--)
        {
            if(s[i-1] > s[i])
            {
                ci = i;
                s[i-1]--;
            }
        }

        while(ci < n) s[ci] = '9',ci++;

        return stoi(s);
    }
};
