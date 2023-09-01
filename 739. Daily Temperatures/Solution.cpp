class Solution {
public:
   
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);

  
    stack<int> stk_indexer;
    for(int  i = n-1; i >= 0;i--)
    {
       
  
        while (!stk_indexer.empty() && temperatures[i] >= temperatures[stk_indexer.top()])
        {
            stk_indexer.pop();
        }
        if(!stk_indexer.empty())
            res[i] =stk_indexer.top() - i  ;
        stk_indexer.push(i);
    }
    return res;
}
};
