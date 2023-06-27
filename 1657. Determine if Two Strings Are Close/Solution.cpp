class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;
        vector<int> counter;
        for(auto x: word1)
           count1[x]++;
        for(auto x: word2)
           {
               if(count1[x] == 0) return false;
               
               count2[x]++;}

        unordered_map<int,int> reverse1;
        for(auto x: count1)
            reverse1[x.second]++;

        unordered_map<int,int> reverse2;
        for(auto x: count2)
            reverse2[x.second]++;

        return reverse1 == reverse2;

    }
};
