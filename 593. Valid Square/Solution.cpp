class Solution {
public:
    int checksize(vector<int>& x,vector<int>& y)
    {
        return pow((x[0] - y[0]),2) + pow((x[1] - y[1]),2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> check({checksize(p1,p2),checksize(p1,p3),checksize(p1,p4),checksize(p2,p3),checksize(p2,p4),checksize(p3,p4)});

        return !check.count(0) && check.size() == 2;
    }
};
