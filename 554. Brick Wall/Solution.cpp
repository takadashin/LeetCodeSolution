class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> chk;

    int maxnum = 0;
    int notmax = accumulate(wall[0].begin(), wall[0].end(),0);
    for (int i = 0; i < wall.size(); i++)
    {
        int sum = 0;

        for (int j = 0; j < wall[i].size(); j++)
        {
            sum += wall[i][j];

            chk[sum]++;
            if(sum != notmax)
            maxnum = max(maxnum, chk[sum]);
        }
    }

    return  wall.size() - maxnum;
}
};
