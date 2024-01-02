class Solution {
public:
    int calPoints(vector<string>& operations) {


        vector<int> scores;

        for(auto x: operations)
        {
            if(x[0] >= '0' && x[0] <= '9' || x[0] ==  '-')
            {
                scores.push_back(stoi(x));
            }
            else if(x == "+")
            scores.push_back(scores[scores.size() -1] + scores[scores.size() -2]);
            else if(x == "D")
            scores.push_back(scores[scores.size() -1] * 2);
            else if(x == "C")
            scores.pop_back();
        }

        return accumulate(scores.begin(),scores.end(),0);
    }
};
