class Solution {
public:
 
bool validPalindrome(string s) {

    int i = 0, j = s.size() - 1;
    bool f1 = true;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            if (f1)
            {
                f1 = false;
                if (s[i + 1] == s[j] && s[j - 1] == s[i]) {
                    int i1 = i +1;
                    int j1 = j;
 
                    while (i1 <= j1)
                    {
                        if (s[i1] != s[j1])
                         break;
                        i1++;
                        j1--;
                    }
                    if(i1 > j1) return true;
                    i1 = i;
                    j1 = j-1;
                    while (i1 <= j1)
                    {
                        if (s[i1] != s[j1])
                         break;
                        i1++;
                        j1--;
                    }
                    if(i1 > j1) return true;
                    return false;


                }
                else if (s[i + 1] == s[j]) i++;
                else if (s[j - 1] == s[i]) j--;

                continue;
            }
            return false;

        }

        i++;
        j--;
    }
    return true;
}
};
