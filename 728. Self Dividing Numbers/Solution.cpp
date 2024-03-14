class Solution {
public:

    bool issd(int num)
    {
        int di = num;
        while(di)
        {

            if((di% 10) == 0 || num % (di% 10) != 0) return false;
            di = di/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right;i++)
        if(issd(i))
        res.push_back(i);
        return res;
    }
};
