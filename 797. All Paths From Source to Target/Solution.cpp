class Solution {
public:


    void bt_allPath(vector<vector<int>>& graph,int current , vector<int> temp, vector<vector<int>>& res)
    {
        if(current == graph.size() -1) {
            temp.push_back(current);
            res.push_back(temp);
        }
        else
        {
            temp.push_back(current);
            for(int x: graph[current])
                    bt_allPath(graph,x,temp,res);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int current = 0; 
        vector<int> temp; 
        vector<vector<int>> res;


        bt_allPath(graph,0,temp,res);

        return res;
    }
};
