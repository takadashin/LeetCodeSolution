class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> qe;

        qe.push({entrance[0],entrance[1]});
        int level = 0;
        int size = qe.size();
        while(!qe.empty())
        {
            size = qe.size();
            while(size--)
            {
                
                // get surround
                auto x = qe.front();
                qe.pop();
                if(maze[x.first][x.second] == '+') continue;
               
                if(x.first == 0 || x.first == maze.size() -1 || x.second == 0 || x.second == maze[0].size() -1)
                    if(level != 0)
                        return level;
                maze[x.first][x.second] = '+';

                if(x.first - 1 >= 0 && maze[x.first - 1][x.second] != '+')
                    qe.push({x.first - 1,x.second});
                if(x.first + 1 < maze.size() && maze[x.first + 1 ][x.second] != '+')
                    qe.push({x.first + 1,x.second});
                if(x.second - 1 >= 0 && maze[x.first][x.second - 1 ] != '+')
                    qe.push({x.first,x.second - 1});
                if(x.second + 1 <  maze[0].size() reddrepass17&& maze[x.first][x.second + 1] != '+')
                    qe.push({x.first,x.second + 1});
                    
                
            }
            level++;
        }
        return -1;
    }

};
