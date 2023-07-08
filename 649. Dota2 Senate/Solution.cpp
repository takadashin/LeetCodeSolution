class Solution {
public:
  
string predictPartyVictory(string senate) {
    int cr = 0, cd = 0;
    int ctr = 0,ctd = 0;
    queue<char> recount;
    
    for (auto x : senate)
    {
        recount.push(x);
        if (x == 'R')
            ctr++;
        else
            ctd++;
    }
     

    while(ctr > 0 && ctd > 0)
    {
        char x = recount.front();
        recount.pop();
        if (x == 'R')
        {
            if (cr > 0)
            {
                ctr--;
                cr--; continue;
                
            }
            else
                cd++;

        }
        else
            if (cd > 0)
            {
                ctd--;
                cd--; continue;
                
            }
            else
                cr++;

        recount.push(x);
    }

    
    return (recount.front() == 'R') ? "Radiant" : "Dire";
    
}
};
