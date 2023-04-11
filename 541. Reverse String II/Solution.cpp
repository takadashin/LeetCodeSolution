class Solution {
public:

    void reversepos(string& s, int low,int high)
    {
        while(low < high)
        {
            swap(s[low],s[high]);
            low++;
            high--;
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0;i < s.size();i+=2*k)
        {
            reversepos(s,i, (i + k-1) < s.size()? (i + k-1): s.size() -1);
        }
        return s;
    }
};
