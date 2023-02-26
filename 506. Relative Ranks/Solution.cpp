class Solution {
public:
    
vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int, int>> indexer;
    for (int i = 0; i < score.size(); i++)
        indexer.push({score[i],i});
    vector<string> res(score.size());
    int counter = 1;

    while(!indexer.empty())
    {
        if (counter == 1)
            res[indexer.top().second] = "Gold Medal";
        else if (counter == 2)
            res[indexer.top().second] = "Silver Medal";
        else if (counter == 3)
            res[indexer.top().second] = "Bronze Medal";
        else
            res[indexer.top().second] = to_string(counter);
            counter++;
        indexer.pop();
    }

    return res;

}
};
