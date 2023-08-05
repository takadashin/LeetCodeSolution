class Solution {
public:
long long totalCost(vector<int>& costs, int k, int candidates) {
   
    priority_queue<int,vector<int>,greater<int>> pickleft,pickright;
    set<int> leftht;
    int i = 0, j = costs.size() - 1;
    long long res = 0;
    while(i <= j && candidates--)
    {
        pickleft.push(costs[i++]);
        if(i-1 < j)
        pickright.push(costs[j--]);

    }
   

    while (k--)
    {
      
        if (!pickleft.empty() && !pickright.empty()) {
            if (pickleft.top() <= pickright.top())
            {
                res += pickleft.top();
                pickleft.pop();
                if (i <= j)
                    pickleft.push(costs[i++]);

            }
            else
            {
                res += pickright.top();
                pickright.pop();
                if (i <= j)
                    pickright.push(costs[j--]);
            }
        }
        else if (!pickleft.empty())
        {
            res += pickleft.top();
            pickleft.pop();
            if (i <= j)
                pickleft.push(costs[i++]);
        }
        else
        {
            res += pickright.top();
            pickright.pop();
            if (i <= j)
                pickright.push(costs[j--]);
        }

    }


    return res;
}
};
