class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for(auto x : points)
        for(auto y: points)
        for(auto z: points)
        {
            if(x == y || y == z || z == x) continue; 
            double temp = 0.5 * abs(x[0] * (y[1] - z[1]) + y[0] * (z[1] - x[1]) + z[0] * (x[1] - y[1]));
            res = max(res,temp);
        }

        return res;
    }
};
