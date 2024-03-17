class MyCalendarThree {
    map<int,int> memo;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        memo[startTime]++;
        memo[endTime]--;
        int booked = 0,res = 0;
        for(auto x: memo)
        {
            booked += x.second;
            res = max(booked,res);
        }

        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
