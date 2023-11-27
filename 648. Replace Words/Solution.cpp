struct TrieNode{
    TrieNode* node[26];
    bool isWord;

    TrieNode()
    {
        for(int i = 0; i < 26;i++) node[i] = NULL;
        isWord = false;
    }
};

class Solution {
    
public:

    void addword(TrieNode * root,string word)
    {
        TrieNode* p = root;
        for(auto x: word)
        {
            if(!p->node[x-'a'])
            p->node[x-'a'] = new TrieNode();
            p = p->node[x-'a'] ;
        }
        p->isWord = true;

    }

    string findword(TrieNode * root,string word)
    {
        TrieNode* p = root;
        string res = "";
        for(auto x: word)
        {
            
            if(p->isWord) return res;
            res += x;
            if(p->node[x-'a']) 
            p = p->node[x-'a'] ;
            else break;
            
        }

        return  word;
        
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string res ;
        string tmp ;
        TrieNode * root = new TrieNode();

        for(auto x: dictionary) addword(root,x);
        while(ss >> tmp)
        {
            res += findword(root,tmp) ;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
