class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {

        int res = INT_MAX;

        unordered_set<int> checklist;
        for (int i = 0; i < fronts.size(); i++)
            if (fronts[i] == backs[i])
                checklist.insert(fronts[i]);

        for (int i = 0; i < fronts.size(); i++) {
            // check if we need to flip the card
            if (fronts[i] != backs[i]) // will flip
            {
                if (checklist.count(fronts[i]) == 0)
                    res = min(res, fronts[i]);

                if (checklist.count(backs[i]) == 0)
                    res = min(res, backs[i]);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
