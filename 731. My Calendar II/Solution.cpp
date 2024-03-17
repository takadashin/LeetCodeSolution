class MyCalendarTwo {
    map<int,int> memo;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        memo[start]++;
        memo[end]--;
        int booked = 0;

        for(auto x: memo)
        {
            booked += x.second;

            if(booked == 3)
            {
                memo[end]++;
                memo[start]--;
                return false;
            }


        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
