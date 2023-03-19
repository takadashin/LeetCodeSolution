class Solution {
public:

    bool isallow(string a,string b){
    
    if(b.size() < a.size()) return false;
    int indexer = 0;
    for(auto x: b)
    {
        if(indexer < a.size() && a[indexer] == x) indexer++;
    }

    return indexer == a.size();
    }


    int findLUSlength(vector<string>& strs) {
        int n = strs.size(),res = -1;
        for(int i = 0;i <n;i++)
        {
            int j = 0;
            for(;j <n;j++)
            {
                if(i == j) continue;
                else if(isallow(strs[i],strs[j]))break;

            }
            if(j == n)
            res = max(res,(int) strs[i].size());

        }
        return res;
    }
};
