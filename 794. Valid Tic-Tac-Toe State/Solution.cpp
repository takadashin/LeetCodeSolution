class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x = 0,o = 0;

        bool runonce = false;
        int winx = 0,wino = 0;
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                 if(board[i][j] == 'X') x++;
                else if(board[i][j]== 'O') o++;

                if(!runonce)
                {
                    if(board[1][j] != ' ' && board[0][j] ==  board[1][j] && board[0][j] ==  board[2][j] ) 
                    {
                        if(board[1][j]== 'X') winx++;
                        else wino++;
                    }
                    runonce = true;
                }
            }
            if(board[i][1] != ' ' && board[i][0] ==  board[i][1] && board[i][0] ==  board[i][2] ) 
            {
                if(board[i][1] == 'X') winx++;
                else wino++;
            }
        }
     

        if(board[1][1] != ' ' && board[0][0] ==  board[2][2] && board[0][0] ==  board[1][1] ) 
        if(board[1][1]  == 'X') winx++;
                else wino++;

        if(board[1][1] != ' ' && board[0][2] ==  board[1][1] && board[2][0] ==  board[1][1] ) 
        if(board[1][1]  == 'X') winx++;
                else wino++;

        if(wino == winx && wino != 0) return false;
        if(winx > wino && x == o) return false;
        if(wino > winx && x > o) return false;
        return x - o <= 1 && x- o >= 0;
    }
};
