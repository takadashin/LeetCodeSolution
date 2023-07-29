class Solution {
public:
    
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> rootlist;
  
    for (int x = 0; x < grid.size(); x++)
        for (int y = 0; y < grid[0].size(); y++)
        {
            if (grid[x][y] == 2)
            {
                rootlist.push({ x,y });
               
            }
        }
    int res = 0;
    while (!rootlist.empty())
    {
        while (!rootlist.empty() && grid[rootlist.front().first][rootlist.front().second] == 3)
            rootlist.pop();
        if (rootlist.empty()) break;
        int size = rootlist.size();
        while (size--)
        {
            
            auto x = rootlist.front();
            rootlist.pop();
            grid[x.first][x.second] = 3;
            if (x.first - 1 >= 0 && grid[x.first - 1][x.second] == 1 )
                rootlist.push({ x.first - 1,x.second });
            if (x.first + 1 < grid.size() && grid[x.first + 1][x.second] == 1)
                rootlist.push({ x.first + 1,x.second });
            if (x.second - 1 >= 0 && grid[x.first][x.second - 1] == 1)
                rootlist.push({ x.first,x.second - 1 });
            if (x.second + 1 < grid[0].size() && grid[x.first][x.second + 1] == 1 )
                rootlist.push({ x.first,x.second + 1 });


        }
        res++;
    }
    for (int x = 0; x < grid.size(); x++)
        for (int y = 0; y < grid[0].size(); y++)
        {
            if (grid[x][y] == 1)
                return -1;
        }
    return res ? --res : 0;

}

};
