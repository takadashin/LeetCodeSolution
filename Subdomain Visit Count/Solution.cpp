class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
    vector<string> res;
    unordered_map<string, int> memo;

    for (auto x : cpdomains)
    {
        int pos = x.find(" ");
        int num = stoi(x.substr(0, pos));
        string lv_str = x.substr(pos + 1);

        memo[lv_str] += num;
        for (int i = 0; i < lv_str.size(); i++)
        {
            if(lv_str[i] == '.')
                memo[lv_str.substr(i+1)] += num;
        }


    }

    for (auto x : memo)
    {
        res.push_back(to_string(x.second) + " " + x.first);
    }
    return res;
}
};
