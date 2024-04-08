
class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> p_store(n+1);

        for(auto x: times)

            p_store[x[0]].push_back({x[1],x[2]});// node,distance


        vector<int> distances(n+1,INT_MAX);
        distances[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qe;// sort queue by distance max first
        qe.push({0,k}); // put on starter point with 0 distance first

        while(!qe.empty())
        {
            int distance = qe.top().first;
            int node = qe.top().second;
            qe.pop();

            if(distance > distances[node]) continue; //skip if current distance already greater than calculated distance

            for(auto x: p_store[node]) // search for any link that start from this node
            {
                int weight = x.second;
                int endnode = x.first;

                if(distance + weight < distances[endnode])
                {
                    distances[endnode] = distance + weight ;
                    qe.push({distances[endnode],endnode});

                }
            }

        }

        int res = 0;
        for(int i = 1;i <= n ;i++)
        {
   
            if(distances[i] == INT_MAX) return -1;
            res = max(res,distances[i]);
        }

        return res;
        
        
    }
};
