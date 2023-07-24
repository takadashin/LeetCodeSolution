class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,map<string,double>> graph;
        vector<double> res(queries.size(),-1);

        for(int i = 0; i < equations.size();i++)
        {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1/values[i];
        }

        for(int i = 0; i < queries.size();i++)
        {
            set<string> visited;
            res[i] = helper(graph,visited,queries[i][0],queries[i][1]);
        }


        return res;
    }

    double helper(map<string,map<string,double>>& graph, set<string>& visited, string from, string to)
    {
        if(graph.find(from) == graph.end()) return -1;
        else if(graph[from].find(to) != graph[from].end()) return graph[from][to];
        else
        {
           
            visited.insert(from);
            for(auto x : graph[from])
            {
                if(!visited.count(x.first))
                {
                    double temp =  helper(graph,visited,x.first,to);
                    if(temp != -1)
                    return temp * x.second;
                }
            }
        }
        return -1;
    }
};
