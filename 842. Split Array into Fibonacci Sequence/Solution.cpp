class Solution {
public:

    bool temp(string& num, vector<int>& ans,int index)
    {
        int n  = num.size();
        if(index >= n && ans.size() >= 3 ) return true; // reach the end of line and have more member as needed

        for(int i = 1;index + i <=n;i++)
        {
            if(num[index] == '0' && i > 1) break;
            int sz = ans.size();
            long long number = stoll(num.substr(index,i));
            if(number > INT_MAX) break;
            if(sz >= 2 && number > (long long) ans[sz-1] + (long long )ans[sz-2]) break;
            if(sz <= 1 || number  == (long long) ans[sz-1] + (long long) ans[sz-2])
            {
                ans.push_back(number);
                if(temp(num,ans,index + i)) return true;
                ans.pop_back();
            }
        }
        return false;



    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        temp(num,ans,0);
        return ans;
    }
};
