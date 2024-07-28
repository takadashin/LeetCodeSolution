class Solution {
public:
    
bool isBipartite(vector<vector<int>>& graph) {
  
    vector<int> colored(graph.size(), -1);
    queue<int> ck;

    int level = ck.size();

    set<int> visited;

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited.count(i))
        {
            ck.push(i);
            visited.insert(i);
            while (!ck.empty())
            {
                level = ck.size();
                while (level--)
                {
                    int index = ck.front();
                    ck.pop();
                    for (auto x : graph[index])
                    {
                        if (colored[x] != -1 && colored[x] == colored[index]) return false;
                        colored[x] = !colored[index];
                        if (!visited.count(x))
                        {
                            ck.push(x); visited.insert(x);
                        }
                    }

                }
            }
        }
    }

    return true;
}
};
