class Solution {
public:
    string decodeString(string s) {
        string res = "";

        stack<pair<string,int>> stk;
        pair<string,int> tag; 
        for(auto x: s)
        {
            if(isdigit(x))
                tag.second += tag.second * 10 + (x -'0');
            else if(x == '[')
            {
                tag.first = res;
                stk.push(tag);
                tag = {"",0};
                res = "";
            }
            else if(x == ']')
            {
                 pair<string,int> tmp = stk.top();
                 stk.pop();
                 for(int i = 0; i < tmp.second;i++) tmp.first += res;
                 res = tmp.first;
            }
            else
            res += x;

        }
        return res;
    }
};
