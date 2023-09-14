class Solution {
public:
    
 
 vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
     int o_r = mat.size();
    int o_c = mat[0].size();
   if (o_r * o_c != r * c) { return mat;}
    else 
     {
         vector<int> temp;
          for (auto x : mat)
     for (auto y : x)
    temp.push_back(y);
    int indexer = 0;
     vector<vector<int>> res(r,vector<int>(c,0));
     for(int i = 0; i < r;i++)
     for(int j = 0; j < c;j++)
        res[i][j] = temp[indexer++];

     return res;
     }
    
 }
};
