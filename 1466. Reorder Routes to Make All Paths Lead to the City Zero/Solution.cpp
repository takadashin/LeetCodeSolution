class Solution {
public:

    int dfs(vector<vector<int>>& direction,vector<bool>& visit,int i)
    {
        int res = 0;
        visit[i] = true;

        for(auto x: direction[i])
        {
            if(!visit[abs(x)])
            res += (x > 0) +  dfs(direction,visit,abs(x));
        }
        return res;

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visit(n,false);

        vector<vector<int>> direction(n);
        for(auto x: connections)
        {
            direction[x[0]].push_back(x[1]);
            direction[x[1]].push_back(-x[0]);
        }

        return dfs(direction,visit,0);

    }
};
