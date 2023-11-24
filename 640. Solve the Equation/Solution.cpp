class Solution {
public:
    
string solveEquation(string equation) {
    stringstream ss(equation);
    string left, right;

    getline(ss, left, '=');
    getline(ss, right, '=');
    left += "+"; right += "+";
    int lcount = 0;
    bool neg = false;
    int temp = 0;
    int xcount = 0;
    bool prex = false;
    for (auto x : left)
    {
        if (x == '-' || x == '+')
        {
            lcount += (neg ? -1 : 1) * temp;
            neg = (x == '-');
            temp = 0;
        }
        if (x == 'x')
        {
            xcount += (neg ? -1 : 1) * (prex?0:((temp) ? temp : 1));
            temp = 0;
        }
        if (x >= '0' && x <= '9') {
            
            temp = temp * 10 + (x - '0');
            prex = (x == '0' && !temp);
        }
    }
    prex = false;
    for (auto x : right)
    {
        if (x == '-' || x == '+')
        {
            lcount -= (neg ? -1 : 1) * temp;
            neg = (x == '-');
            temp = 0;
        }
        if (x == 'x')
        {
            xcount -= (neg ? -1 : 1) * (prex?0:((temp) ? temp : 1));
            temp = 0;
        }
        if (x >= '0' && x <= '9') {
            
            temp = temp * 10 + (x - '0');
            prex = (x == '0' && !temp);
        }
    }
    if(!xcount) return lcount ? "No solution": "Infinite solutions";
    int res = -1 * lcount / xcount;

    string ans = to_string(res);
    return "x=" + ans;

}
};
