class Solution {
public:
    int nextGreaterElement(int n) {
        string test = to_string(n);
        int siz = test.size();
        int index = 0;

        for(int i = index+1;i < siz;i++)
        {
            if(test[i-1] < test[i])
            index = i;
        }
        if(index == 0) return -1;
        int j = index;
         for(int  i = index +1;i < siz;i++)
            {
                if(test[i] > test[index-1] && test[i] < test[index])
                {j = i;}

            }
        swap(test[index-1],test[j]);
        sort(test.begin()+index,test.end());

        try
           { return stoi(test);}
        catch(...)
        {return -1;}
    }
};
