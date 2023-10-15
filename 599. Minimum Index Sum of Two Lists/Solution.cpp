class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int m = list1.size();
        int n = list2.size();
        vector<string> res;
        unordered_map<string,int> test;
        int com = INT_MAX;
        for(int i = 0 ; i < m;i++)
            test[list1[i]] = i;
        int j = 0;
        for(int i = 0 ; i < n;i++)
        {
            if(test.count(list2[i]))
            {
                j = test[list2[i]];
                if(com > (i+j))
                {com = i+j; 
                res.clear();
                res.push_back(list2[i]);}
                else if(com == (i+j))
                res.push_back(list2[i]);
            }
            
        }
        return res;
    }
};
