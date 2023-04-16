class Solution {
public:
  

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
    int r = mat.size();
    int c = mat[0].size();
    queue<pair<int, int>> q_list;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] == 0)// handle code here
                q_list.push({ i,j });
            else
                mat[i][j] = -1;

    vector<pair<int, int>> dr_4 = { {1,0},{0,1 },{-1,0 },{0,-1 } };
    while (!q_list.empty())
    {
        int distance = 0;
        auto x = q_list.front();
        q_list.pop();
        for (auto i : dr_4)
        {
            if (x.first + i.first >= 0 && x.first + i.first < r && x.second + i.second >= 0 && x.second + i.second < c && mat[x.first + i.first][x.second + i.second] == -1)
            {
                mat[x.first + i.first][x.second + i.second] = mat[x.first][x.second] + 1;
                q_list.push({ x.first + i.first, x.second + i.second });
            }

        }
    }
    return mat;
}
};
