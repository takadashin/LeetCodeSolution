class MyCalendar {
    map<int,int> memo;


public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto target  = memo.lower_bound(start);

        if(target != memo.end() && target->first < end) 
        return false;
 
        if(target != memo.begin() && (--target)->second > start) return false;

        memo.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
