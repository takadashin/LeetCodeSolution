class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> check({'a', 'e', 'i', 'o',  'u'});
        int nc = 0;
        int head=  0, tail = k-1;
        for(int i = 0;i < k;i++)
            if(check.count(s[i]) > 0) nc++;
        int res = nc;
        while(tail < s.size())
        {
            tail++;
            nc = nc + (check.count(s[tail]) > 0? 1:0) - (check.count(s[head]) > 0? 1:0);
            res = max(nc,res);
            head++;
        }
        return res;
    }
};
