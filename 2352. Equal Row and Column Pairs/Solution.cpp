class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int r= grid.size(), c= grid[0].size();
        unordered_map<string,int> row,col;
        string temp ;
        for(int i = 0; i < r;i++)
        {
            temp = "";
            for(int j = 0; j < c;j++) temp += to_string(grid[i][j]) + ",";
            
            row[temp]++;
        }
        for(int j = 0; j < c;j++) 
        
        {
            temp = "";
            for(int i = 0; i < r;i++) temp += to_string(grid[i][j]) + ",";
           
            col[temp]++;
        }
        int res = 0;
        for(auto x: col)
        {
            if(row[x.first] > 0)
            res += row[x.first] * x.second;
        }
        
        
        return res;
    }
};
