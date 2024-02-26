class Solution {
public:
    string toLowerCase(string s) {
        int test= 0;
        string res = "";
        for(auto x : s)
        {
            if(x >= 'A' && x <= 'Z')
                {
                    test = x - 'A';
                  
                    res.push_back('a' + test);
                }
            else
            res.push_back(x);
        }
        return res;
    }
};
