class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res = "";
        int n = s.size();
        unordered_map<int,int> indi ;
        for(int i = 0; i < indices.size();i++) {
            if( s.substr(indices[i],sources[i].size()) == sources[i] )
                indi[indices[i]] =  i;
     
        }
        for(int i = 0; i < n;i++)
        {
            if(indi.count(i) > 0)
            {
                res += targets[indi[i]];
                i+= sources[indi[i]].size() - 1;
            }
            else
            res += s[i];
        }

        return res;
    }
};
