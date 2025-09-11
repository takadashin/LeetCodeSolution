class Solution {
public:

    vector<int> flip(vector<int> origin)
    {
        vector<int> res;

        for(int i = origin.size() -1; i >= 0;i--)
        res.push_back(origin[i]);
        return res;
    }

    vector<int> inverse(vector<int> origin)
    {
        vector<int> res;

        for(int i = 0; i < origin.size();i++)
        res.push_back(!origin[i]);
        return res;
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res;
        for(auto x : image)
        {
            res.push_back(inverse(flip(x)));
        }
        return res;
    }
};
