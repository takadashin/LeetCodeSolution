class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        
        int i = 1,j  = k + 1;

        bool odd = true;

        while(i <= j)
        {
            res.push_back(odd ? i++:j--);
            odd = !odd;
        }
        j = k+1;
        while( ++j <= n)
        {
            res.push_back(j);
        }

        return res;
    }
};
