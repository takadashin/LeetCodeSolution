class Solution {
public:
    int findparent(int x,vector<int>& par)
    {
        if(x == par[x]) return x;
        par[x] = findparent (par[x],par);
        return par[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);
        vector<int> rank(n+1,1);
        for(int i = 0;i < n+1;i++) par[i] = i;
        int px,py;
        for(auto x: edges)
        {
             px = findparent(x[0],par) ,py = findparent(x[1],par);
            if(px == py) return x;
            
            if(rank[px] == rank[py])
            {
                par[py] = px; 
                rank[px]++;
            }
            else if(rank[px] > rank[py])
            par[px] = par[py]; 
            else
            par[py] = par[px];
        }

        return {};
    }
};
