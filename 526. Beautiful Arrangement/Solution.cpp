class Solution {
public:
int countArrangement(int n) {
    // first populate a simulate array 
    vector<bool> visited(n+1,false);
    int res = 0;
    createpermu(visited, 1,res);
     return res;
}
    void createpermu(vector<bool>& visited, int idx, int& counter)
{
    //using backtracking to create a permutation of n elements
    //remember idx start at 0
    
    if (idx == visited.size())
    {
        counter++;
        return;
    }
    else
    {
        for (int i = 1; i < visited.size(); i++)
        {
            if (visited[i] == false && (i % idx == 0 || idx % i == 0))
            {
                visited[i] = true;
                createpermu(visited, idx + 1, counter);
                visited[i] = false;
            }
        }
    }
}
};
