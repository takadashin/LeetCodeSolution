class Solution {
public:

    // x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2
    //rec1[0] = x1
    //rec1[1] = y1
    //rec1[2] = x2
    //rec1[3] = y2
    //rec2[0] = x3
    //rec2[1] = y3
    //rec2[2] = x4
    //rec2[3] = y4
     bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (rec1[0]  < rec2[2] &&  rec2[0] < rec1[2]  && rec1[1] <  rec2[3] && rec2[1] < rec1[3]) ;
    }
};
