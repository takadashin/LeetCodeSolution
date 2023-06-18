class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('!');
        int s = 0,os = 0;
        int i = 1;char last = ' ';
        int index = 0;
        for(auto x: chars)
        {
            if(s == 0 || last != x)
            {
                if(i != 1)
                {

                 os = s;
                while(i)
                {
                    if( os != s )
                    for(int y = s;y > os;y--)
                    {
                        swap(chars[y-1] ,chars[y]);
                    }
                    chars[os] = (i%10) + '0';
                    s++;
                    i /= 10;
                    
                }}
                if(x == '!') break;
                last = x;
                chars[s] = x;
                
                s++;i = 1;
            }
            else
            i++;
        }
       
        return s;
    }
};
