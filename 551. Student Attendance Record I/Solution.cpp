class Solution {
public:
    bool checkRecord(string s) {
      bool test=  false;
      int counter = 0;
      for(auto x: s)
      {
        if(x == 'L') counter++;
        else
        counter =0;
        test = test || (counter >= 3);
      }

      return count(s.begin(),s.end(),'A') < 2 &&  !test;
    }
};
