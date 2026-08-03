class Solution {
public:
    int helper(string s,int i)
    {
        int skip = 0;
        while(i >= 0)
        {
            if(s[i] == '#')
            {
                skip++;
                i--;
            }
            else if(skip > 0)
            {
                skip--;
                i--;
            }
            else break;
        }
        return i;
    }

    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size() -1;
        while(i >= 0 || j >= 0)
        {
            i = helper(s,i);
            j = helper(t,j);
            if( i < 0 && j < 0) return true;
            if(i < 0 || j < 0) return false;
            if(s[i]!= t[j]) return false;
            i--;
            j--;
        }
        return true;
    }
};
