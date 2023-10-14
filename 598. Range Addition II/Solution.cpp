class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
       
        if(ops.empty()) return m * n;
        else
        {
            int minx = INT_MAX;
            int miny = INT_MAX;
            for(int i = 0; i < ops.size();i++)
            {
                minx = min(minx,ops[i][0]);
                miny = min(miny,ops[i][1]);
                
            }
            return minx*miny;
            
        }

    }
};
