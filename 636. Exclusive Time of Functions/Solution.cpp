class Solution {
    struct Log{
        int st;
        string status;
        int ed;
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<Log> test;
    vector<int> res(n, 0);
    
    for (auto x : logs)
    {
        stringstream ss(x);
        string top, bottom, status;
        getline(ss, top, ':');
        getline(ss, status, ':');
        getline(ss, bottom, ':');
        Log wut { stoi(top),status, stoi(bottom)};

        if (status == "start") test.push(wut);
        else
        {
            int len = wut.ed - test.top().ed + 1;
            res[ test.top().st] += len;
            
            test.pop();
            if(!test.empty()) 
            {
                res[test.top().st] -= len;
            }
        }

        
    }
    return res;

}
};
