class Solution {


    
class Trie
{
    struct TrieNode
    {
        TrieNode* list[26];
        bool isWord;
        TrieNode()
        {
            for (auto& x : list)
            {
                x = NULL;
            }
            isWord = false;
        }
    };
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }

    void AddNode(string data)
    {
        TrieNode* p = root;
        for (auto x : data)
        {
            if (!p->list[x - 'a'])
                p->list[x - 'a'] = new TrieNode();
            p = p->list[x - 'a'];
        }
        p->isWord = true;
    }


    void dfp_helper(TrieNode* p,vector<string>& res,string tmp)
    {
       
        if (!p) return;
        else if (res.size() == 3) return;
        else
        {
            if (p->isWord) res.push_back(tmp);

            for (int i = 0; i < 26; i++)
            {
                if (p->list[i])
                {
                    char x = 'a' + i;
                    tmp.push_back(x);
                    dfp_helper(p->list[i], res, tmp);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<string> startwith(string data)
    {
        vector<string> res;
        TrieNode* p = root;

        for (auto x : data)
        {
            if (!p->list[x - 'a'])
                return res;
            p = p->list[x - 'a'];

        }
        dfp_helper(p, res,data);
        return  res;


    }

};
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* test = new Trie();
        for(auto x: products)
            test->AddNode(x);
        vector<vector<string>> ans;
        string s_word = "";
        for(auto x: searchWord)
        {
            vector<string> tmp ;
            s_word.push_back(x);
            tmp = test->startwith(s_word);
            ans.push_back(tmp);
        }
        return ans;
    }
};
