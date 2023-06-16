class Solution {
public:
    string reverseVowels(string s) {
        set<char> s_check({'a','e','i','o','u','A','E','I','O','U'});

        int  i = 0, j = s.size()-1;
        while(i < j)
        {
            if(s_check.count(s[i]) > 0 && s_check.count(s[j]))
            {swap(s[i],s[j]);i++;j--;continue;}
            
            if(s_check.count(s[i]) == 0) i++;
            if(s_check.count(s[j]) == 0) j--;


        }
        return s;
    }
};
