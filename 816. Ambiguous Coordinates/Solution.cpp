class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        
        vector<string> res;

        s = s.substr(1,s.size()-2);
        int n = s.size();

        for(int i = 1;i < n;i++)
        {
            string left = s.substr(0,i);
            string right = s.substr(i);

            vector<string> r_left = helper(left);
            vector<string> r_right = helper(right);


            for(auto x: r_left)
            for(auto y: r_right)
            res.push_back("("  + x + ", " + y + ")");
        }

        return res;
    }

    vector<string> helper(string s)
    {
        
        vector<string> res;
        if(s[0] != '0' || s == "0") res.push_back(s);
        
        int n = s.size();
         for(int i = 1;i < n;i++)
        {
            string left = s.substr(0,i);
            string right = s.substr(i);

            if(left[0] == '0' && left.size() > 1) continue;
            if(right.back() == '0') continue;

            res.push_back(left + '.' + right);
        }


        return res;

    }
};
