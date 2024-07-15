class Solution {
public:

    void bk_p(string s, int ind,vector<string>& res){
        if(ind == s.size())
        {
            res.push_back(s);
            return;
        }
        bk_p(s,ind+1,res);
        
        if(isalpha(s[ind]))
        {
            s[ind] = islower(s[ind])? toupper(s[ind]): tolower(s[ind]);
            bk_p(s,ind+1,res);
            s[ind] = islower(s[ind])? toupper(s[ind]): tolower(s[ind]);
        } 

        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        bk_p(s,0,res);
        return res;
    }
};
