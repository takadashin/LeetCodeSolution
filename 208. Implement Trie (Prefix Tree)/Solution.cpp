class Trie {

    struct TrieNode{
        TrieNode* list[26];
        bool isword = false;
        TrieNode()
        {
            for(auto &x: list)
            x = NULL;
            isword =false;
        }
    };

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * p = root;

        for(auto x: word)
        {
            if(p->list[x-'a'] == NULL)
                p->list[x-'a'] = new TrieNode();
            
            p = p->list[x-'a'];
            
        }
        p->isword = true;
    }
    
    bool search(string word) {
        TrieNode * p =root;

        for(auto x: word)
        {
            if(p->list[x-'a'] == NULL)
                return false;
            
            p = p->list[x-'a'];
            
        }
        return p->isword;
    }
    
    bool startsWith(string prefix) {
        TrieNode * p = root;

        for(auto x: prefix)
        {
            if(p->list[x-'a'] == NULL)
                return false;
            
            p = p->list[x-'a'];
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
