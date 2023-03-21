class Solution {
public:

    bool isAllowed(string a,string b)
    {
        if(b.size() < a.size()) return false;
        int indexer = 0;
        for(auto x: b)
        {
            if(indexer < a.size() && a[indexer] == x) indexer++;
        }

        return indexer == a.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string res = "";
        for(auto x: dictionary)
        {
            if(isAllowed(x,s))
            {
                if(res.length() < x.length() || (res.length() == x.length() && res > x))
                res = x;
                


            }
        }

        return res;
    }
};
