class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> canVisited;
        set<int> Visited;
        for(auto x: rooms[0])
        canVisited.push(x);
        Visited.insert(0);
        while(!canVisited.empty())
        {
            int target = canVisited.front();
            canVisited.pop();
            
            if(!Visited.count(target))
            {
                 for(auto x: rooms[target])
                     if(!Visited.count(target))
                        canVisited.push(x);
            }
            Visited.insert(target);

            
        }

        for(int i = 0;i < rooms.size();i++)
        {
            cout << i << endl;
            if(!Visited.count(i))
                return false;
        }
        return true;
    }
};
