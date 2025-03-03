class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph += " ";
        unordered_set<string> banword(banned.begin(),banned.end());
        unordered_map<string,int> intword;
        string word = "";
        for(auto x: paragraph)
        {
            if(isalpha(x))
            {
                x = tolower(x);
                word += x;
            }
            else if(!word.empty())
            {
                if(banword.count(word) == 0)
                intword[word]++;
                word = "";
            }
        }


        int count = 0;
        string res = "";
        for(auto x: intword)
        {
            if(count < x.second)
            {
                res = x.first;
                count = x.second;
            }
        }

        return res;

    }
};
