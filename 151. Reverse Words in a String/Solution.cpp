class Solution {
public:
    string reverseWords(string s) {
        bool sp = true;
        int spot = 0;
        reverse(s.begin(),s.end());

        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == ' '&& sp == true)
            {s.erase(s.begin()+i);i--;continue;}

            if(s[i] != ' '&& sp == true)
            {sp = false;spot = i;}

            if(s[i] == ' ')
            {reverse(s.begin()+spot,s.begin()+i);sp = true;}



        }
        if(s[s.size()-1] == ' ')
        {
            s.erase(s.end()-1);
        }
        else
        reverse(s.begin()+spot,s.end());
        return s;
    }
};
