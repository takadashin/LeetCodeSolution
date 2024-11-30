class Solution {
public:

    bool issafe(vector<vector<int>>& graph,int index,vector<int>& colored)
    {
        colored[index] = 1;
        for(auto x: graph[index])
        {
            if(  colored[x] == 1 || (colored[x] == 0  && issafe(graph,x,colored) )  ) // dps after checking if colored is 0
            return true;
        }

        colored[index] = 2;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(),0),res;
        for(int i = 0; i < graph.size();i++)
        {
            if(colored[i] == 2 || !issafe(graph,i,colored) ) res.push_back(i);
        }
        return res;
    }
};
