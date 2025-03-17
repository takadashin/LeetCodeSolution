class Trie{
    public:
    Trie* list[26];
    int count ;
    Trie()
    {
        for(int i = 0; i < 26;i++) list[i] = NULL,count = 0;
    }
    Trie* get(char x)
    {
        if(list[x-'a'] == NULL) list[x-'a'] = new Trie(), count++;

        return list[x-'a'];

    }


};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<Trie*,int> memo;
        Trie* head = new Trie();
        // go through all item in words
        for(int  i = 0; i < words.size();i++)
        {
            Trie* temp = head;

            for(int j = words[i].size() -1; j >= 0;j--)
            temp = temp->get(words[i][j]);

            memo[temp] = i;
        }

        int res = 0;
        for(auto x: memo)
        {
            if(x.first->count == 0) // if count is > then 0 . that means this is not the leaf of the end of the word => invalid
            res += words[x.second].size() + 1; // # is count as 1 . Not sure why # is matter in this context since it can only complicated the whole processes
        }

        return res;
    }
};

