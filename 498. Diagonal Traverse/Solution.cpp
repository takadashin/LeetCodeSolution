class Solution {
public:
    
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    bool up = true;
    int m = mat.size();
    int n = mat[0].size();
    int movement = m + n - 2;
    int moves = 0;
    vector<int> res;
    int i = 0, j = 0;
    while (moves <= movement)
    {
        
        if (up)
        {
            i = moves < m ? moves : m;
            j = moves - i;

            while (i >= 0 )
            {
                if (j < n && i < m)  res.push_back(mat[i][j]);

                i--;
                j = moves - i;
            }
        }
        else
        {
            j = moves < n ? moves : n;
            i = moves - j;

            while (j >= 0 )
            {
                if (j < n && i < m) res.push_back(mat[i][j]);

                j--;
                i = moves - j;
            }
        }

        up = !up;

        moves++;
    }
    return res;
}
};
