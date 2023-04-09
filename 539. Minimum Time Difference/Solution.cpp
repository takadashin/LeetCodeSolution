class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int total = 24*60;

        int hour,mins;
        vector<int> list;
        for(auto x:timePoints)
        {
            hour = stoi(x.substr(0,2));
            mins = stoi(x.substr(3));
            list.push_back(hour * 60 + mins);
        }
        sort(list.begin(),list.end());
        int res = INT_MAX;
        for(int i = 1; i < list.size();i++)
        {
            res = min(res, list[i]- list[i -1]);
        }
        res = min(res, list[0] + total - list[list.size()-1]);

        return res;
    }
};
