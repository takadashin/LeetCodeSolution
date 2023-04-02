class Solution {
public:
    
int sur_board(vector<vector<char>>& board, int x, int y)
{
    int r = board.size();
    int c = board[0].size();
    int res = 0;
    res += (x - 1 >= 0 && board[x - 1][y] == 'M');//top
    res += (y - 1 >= 0 && board[x][y-1] == 'M');//left
    res += (x + 1 < r && board[x + 1][y] == 'M');//bottom
    res += (y + 1 < c && board[x][y + 1] == 'M');//right
    res += (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'M');//topleft
    res += (x - 1 >= 0 && y + 1 < c && board[x - 1][y + 1] == 'M');//topright
    res += (x + 1 < r && y - 1 >= 0 && board[x + 1][y - 1] == 'M');//bottomleft
    res += (x + 1 < r && y + 1 < c && board[x + 1][y + 1] == 'M');//bottomright

    return res;
}
void dfs_update(vector<vector<char>>& board, int x, int y)
{
    //base case is when you detect bomb in this spot
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() )
        return;
    else if (board[x][y] == 'M')
        board[x][y] = 'X';
    else if (board[x][y] == 'E' && sur_board(board,x,y) > 0)
    {

        board[x][y] = '0' + sur_board(board, x, y);
    }
    else if (board[x][y] == 'E')
    {
        board[x][y] = 'B';
        dfs_update(board, x + 1, y);
        dfs_update(board, x , y + 1);
        dfs_update(board, x - 1, y);
        dfs_update(board, x , y - 1);
        dfs_update(board, x + 1, y + 1);
        dfs_update(board, x - 1 , y + 1);
        dfs_update(board, x + 1, y - 1);
        dfs_update(board, x - 1  , y - 1);

    }
}


vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

    dfs_update(board, click[0], click[1]);

    return board;
}
};
