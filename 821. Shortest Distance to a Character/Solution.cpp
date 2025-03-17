class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        int pos = -s.size();

        //lướt từ trái qua phải và tìm phần tử từ giá trị trái
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == c) pos = i;
            res.push_back(abs(pos - i) );
        }
        for(int i=  s.size() -1;i >= 0;i--)
        {
            if(s[i] == c) pos = i;

            res[i] = min(res[i],abs(pos - i));

        }

        return res;


    }
};
