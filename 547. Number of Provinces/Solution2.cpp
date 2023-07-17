class Solution {
public:
    


void dfs_findCircleNum(vector<vector<int>>& isConnected, vector<bool>& Visited,int index)
{
    if (!Visited[index]) {
        Visited[index] = true;
        for (int j = 0; j < isConnected[index].size(); j++) {
            if (isConnected[index][j] && !Visited[j])
                dfs_findCircleNum(isConnected, Visited, j);

        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    
    vector<bool> Visited(isConnected.size(), false);;
    int count = 0;

    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!Visited[i])// not found
        {
            dfs_findCircleNum(isConnected, Visited, i);
            count++;
            
        }
    }


    return count;
}
};
