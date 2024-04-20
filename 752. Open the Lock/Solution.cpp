class Solution {
public:
    vector<string> rotate(string x,int index)
    {
        vector<string> res(2,x);

        res[0][index] = '0' + (res[0][index] - '0' + 1 ) % 10;

        res[1][index] = '0' + (res[1][index]  - '0' - 1 + 10) % 10;

        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> stop(deadends.begin(),deadends.end()), visited;

        if(stop.count("0000")) return -1;
        if(target == "0000") return 0;
        queue<string> qe;
        qe.push("0000");visited.insert("0000");
        int step = 0, level = 0;
        while(!qe.empty())
        {
            level = qe.size();
            step++;
            while(level--)
            {
                string ans = qe.front();
                qe.pop();

                for(int i = 0;i < 4;i++)
                {
                    vector<string> neig = rotate(ans,i);
                    for(auto x: neig)
                    {
                       
                        if(!stop.count(x) && !visited.count(x))
                        {
                            if(x == target) return step;
                            else 
                            {
                                visited.insert(x);
                                qe.push(x);
                            }

                        }
                    }

                   
                }
            }
        }

        return -1;


        

    }
};
