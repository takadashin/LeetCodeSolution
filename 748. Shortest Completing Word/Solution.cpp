class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> storage(26,0);
        int size = 0;
        for(auto x: licensePlate)
        {
            if(x >= 'a' && x <= 'z')
            storage[x-'a']++,size++;
            else if(x >= 'A' && x <= 'Z')
            storage[x-'A']++,size++;

       
        }
        string res = "";
        for(auto x: words)
        {
            vector<int> temp = storage;
            int t_size = size;
 
            for(auto y:x)
            {
                if(temp[y - 'a'] > 0) temp[y - 'a']--,t_size--;
         
            }

            if(t_size == 0) res = (res.size() == 0 || res.size() > x.size() ? x:res);
        }
        return res;
    }
};
