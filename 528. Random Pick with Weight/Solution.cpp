
class Solution {
public:
    vector<int> list;
    int prep;
    Solution(vector<int>& w) {
        list.clear();
        prep = 0;
        for (int i = 0; i < w.size(); i++)
        {
            prep += w[i];
           
            
            list.push_back(prep);
        }
    }

    int pickIndex() {
        int rd_indx = rand() % prep;
        auto it = upper_bound(list.begin(), list.end(), rd_indx);
        return it - list.begin();

    }
};
