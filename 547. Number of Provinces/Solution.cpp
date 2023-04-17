class Solution {
public:
    
 int findCircleNum(vector<vector<int>>& isConnected) {
     int counter = 0;
     set<int> visited;
     queue<int> work;

     for (int i = 0; i < isConnected.size(); i++)
     {
         if (visited.count(i) == 0)
         {
             counter++;
             work.push(i);
             visited.insert(i);
             while (!work.empty())
             {
                 int index = work.front();
                 work.pop();
                 for (int j = 0; j < isConnected[index].size(); j++)
                 {
                     // find all connected province
                     if (isConnected[index][j] == 1 && visited.count(j) == 0)
                     {
                         work.push(j);
                         visited.insert(j);
                     }
                 }
             }
         }
     }

     return counter;
 }
};
