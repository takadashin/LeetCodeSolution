class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> memo{'a', 'e', 'i', 'o',  'u','A', 'E', 'I', 'O',  'U'};
        string w, res;
        istringstream ss(sentence);
        int counter = 0;

        while(ss >> w)
        {
            if(memo.count(w[0]) > 0)
            res = res + ' ' + w + "ma";
            else
            res = res + ' ' + w.substr(1) + w[0] + "ma" ;
            counter ++;
            int temp = counter;
            while(temp--)
            res += "a";

   
        }
        return res.substr(1);
    }
};
