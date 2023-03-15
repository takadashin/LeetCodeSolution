class Solution {
public:
    bool  isnotCap(char x)
    {
         return (x - 'a' >=0 && x - 'a' <= 26);
    }
    bool detectCapitalUse(string word) {

        int size = word.size();

        if(size == 1)
        return true;
        
        bool test = isnotCap(word[1]);
        if (isnotCap(word[0]) && test != isnotCap(word[0]))
            return false;


        for(int i = 1;i < word.size();i++)
        {
            if(test != isnotCap(word[i]))
            return false;
            
        }
        return true;
    }
};
