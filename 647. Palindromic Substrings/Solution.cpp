class Solution {
public:

    int ispalindrome(string s,int i,int j)
{
    int count = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j])
        {count++;i--;j++;} ;
    return count;
}
int countSubstrings(string s) {
    int n = s.size();
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += ispalindrome(s,i,i);
        res += ispalindrome(s,i,i+1);
    }
 
    return res;
}
};
