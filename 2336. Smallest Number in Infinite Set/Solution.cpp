class SmallestInfiniteSet {
   
    set<int> check;
public:
    SmallestInfiniteSet() {
      
        check.clear();
        for(int i = 1;i <= 1000;i++)
        {check.insert(i);}
    }
    
    int popSmallest() {
        auto pos = check.begin();

        int x = *pos;
        check.erase(pos);
        return x;
    }
    
    void addBack(int num) {
     
        check.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
