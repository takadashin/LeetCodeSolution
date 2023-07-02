class Solution {
public:
    string removeStars(string s) {
        int writer = 0;

        for(int i = 0; i < s.size();i++)
        {
            if(s[i] == '*' && writer > 0)
            {writer--;continue;}
            swap(s[writer],s[i]);
            writer++;
            
        }
        return s.substr(0,writer);
    }
};
