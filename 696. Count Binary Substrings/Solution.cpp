class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0,cur = 1,res =0;
        for(int i = 1;i < s.size();i++)
        {
            if(s[i-1] == s[i]) cur++;
            else
            {
                res += min(pre,cur);
                pre = cur;
                cur = 1;

            }
        }
        return res + min(pre,cur);
    }
};
