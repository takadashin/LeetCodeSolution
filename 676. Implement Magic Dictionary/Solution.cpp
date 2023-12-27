class MagicDictionary {
    
public:
    

    struct Trie{
        Trie* lis[26];
        bool isWord = false;
        Trie()
        {
            for(auto& x:lis)
            x = NULL;
            isWord = false;
        }

        void addword(string w)
        {
            Trie* p = this;
            for(auto x: w)
            {
                if(!p->lis[x-'a']) p->lis[x-'a'] = new Trie();
                p = p->lis[x-'a'];

            }

            p->isWord = true;
        }

        
    };
    Trie* root;
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto x: dictionary)
            root->addword(x);

    }
    bool find(string w)
        {
             Trie* p = root;
            for(auto x: w)
            {
                if(!p->lis[x-'a']) return false;
                p = p->lis[x-'a'];

            }

            return p->isWord;
        }
    bool search(string searchWord) {
        
        string temp = searchWord;
        for(int i = 0; i < temp.size();i++)
        {
            for(int j = 0;j  < 26;j++)
            {
                if(j + 'a' == searchWord[i])
                continue;
                temp[i] = j + 'a';

                if(find(temp)) return true;
            }
            temp[i] = searchWord[i];
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
