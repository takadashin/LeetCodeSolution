class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size() != end.size()) return false;
        int n = start.size();
        string  s,e;
        for(int i = 0;i < n;i++)
        {
            if(start[i] != 'X') s += start[i];
            if(end[i] != 'X') e += end[i];
        }

        if(s != e) return false;

        int i =0,j = 0;
        while( i < n && j < n)
        {
            if(start[i] == 'X') i++;
            else if(end[j] == 'X') j++;
            else
            {
                if(start[i] == 'L' && i < j) return false;
                else if(start[i] == 'R' && i > j) return false;
                i++;
                j++;
            }
        }
        return true;
    }
};
