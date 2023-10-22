class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> me;
        int whichmax = 0;
        for(auto x: tasks)
        {
            me[x]++;
            whichmax = max(whichmax,me[x]);
        }

        int  res = (whichmax - 1) * (n + 1); //exclude the last cycle and include the n space plus the current max character
        for(auto x: me)
        if(x.second == whichmax) res++;
        return tasks.size() > res? tasks.size():res;
     }
};
