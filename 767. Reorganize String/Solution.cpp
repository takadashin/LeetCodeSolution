class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mem(26,0);

        string res=  "";
        for(auto x: s) mem[x - 'a']++;
        priority_queue<pair<int,char>> pq;

        for(int i = 0; i < 26;i++) 
        if(mem[i]> 0)
        pq.push({mem[i], i + 'a'});

        pair<int,char> pre = {-1,'?'};
        while(!pq.empty()){
            
            auto current = pq.top();
            pq.pop();

            res += current.second;
            current.first--;

            if(pre.first > 0)
            pq.push(pre);

            pre = current;
        }

        if(res.size() == s.size()) return res;
        else return "";
    }
};
