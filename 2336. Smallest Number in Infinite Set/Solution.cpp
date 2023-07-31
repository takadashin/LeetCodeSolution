class SmallestInfiniteSet {
    int current;
    set<int> check;
public:
    SmallestInfiniteSet() {
      
        check.clear();
        current = 1;
    }
    
    int popSmallest() {
        if(check.size())
        {auto pos = check.begin();

        int x = *pos;
        check.erase(pos);
         return x;
        }
        else
        {
            current++;
            return current -1;
        }
       
    }
    
    void addBack(int num) {
        if(num < current)
        check.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
