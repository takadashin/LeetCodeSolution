class Solution {
public:
struct what_is_compare
{
    bool operator() (const vector<int>& struct1, const vector<int>& struct2)
    {
        return (struct1[1] < struct2[1]);
    }
};
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),what_is_compare());
        int sum = 0;
        priority_queue<int> thisqueue;
        for(auto x: courses)
        {
            sum += x[0];
            thisqueue.push(x[0]);
            if(sum > x[1])
            {
                sum -= thisqueue.top();
                thisqueue.pop();
            }

           
       
        }
        return thisqueue.size();

    }
};
