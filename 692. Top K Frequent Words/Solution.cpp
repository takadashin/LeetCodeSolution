class Solution {
public:
struct customcompare{
    bool operator() (pair<int,string> & a,pair<int,string>& b)
    {
        if(a.first != b.first)  return a.first < b.first;
        else
        return a.second > b.second;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hm;
        for(auto x: words)
        hm[x]++;

        priority_queue<pair<int,string>,vector<pair<int,string>> ,customcompare> qe;
        for(auto x: hm) qe.push({x.second,x.first});
        
        vector<string> res;
        while(k--)
        {
            auto x = qe.top();
            qe.pop();
            res.push_back(x.second);
        }
    
        return res;

    }
};
