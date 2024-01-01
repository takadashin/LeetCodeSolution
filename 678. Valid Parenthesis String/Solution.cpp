class Solution {
public:

    bool checkValidString(string s) {
        int maxc = 0,minc = 0;

        for(auto x: s)
        {
            if(x == '(')
            {
                maxc++;
                minc++;
            }
            else if(x == ')')
            {
                maxc--;
                minc--;
            }
            else
            {
                maxc++;
                minc--;
            }
            if(maxc < 0) return false;

            minc = max(minc,0);
        }
        return minc == 0;
    }
};
