class Solution {
public:

    void tester ( vector<int>& memo,string& plt,string param )
    {
        memo.clear();
        plt.clear();
        for(auto x: param)
        {

            if(plt.empty() || plt[plt.size()-1] != x)
            plt.push_back(x), memo.push_back(1);
            else
            memo[memo.size()-1]++;
        }
    }
    int expressiveWords(string s, vector<string>& words) {
        string plt = "";
        vector<int> memo;
        int counter = 0;
        
        tester(memo,plt,s);

        string tem = "";
        vector<int> mem;
        int res = 0;
        for(auto x: words)
        {
            tester(mem,tem,x);

            if(tem == plt)
            {
                int i;
                for(i = 0;i < tem.size();i++)
                {
                    if(memo[i] <= 2 && memo[i] != mem[i]) break;
                    else if(memo[i] < mem[i]) break;
                }
                
                if(i >= tem.size()) res++;
            }
        }
        
        return res;
    }
};
