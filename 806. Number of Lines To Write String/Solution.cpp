class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.size();
        int res = 0;
        int counter = 0;
        for(int  i = 0; i < n;i++)
        {
            
            if(counter + widths[ s[i] - 'a'] > 100)
            {
                res++;
                counter = 0;

            }
            counter += widths[ s[i] - 'a'];
        }
        
        return {(res + (counter > 0 ? 1:0)),counter};

    }
};
