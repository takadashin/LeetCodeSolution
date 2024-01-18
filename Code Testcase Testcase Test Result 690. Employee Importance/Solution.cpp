/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> memo;

        for(auto x: employees)
            memo[x->id] = x;

        int res = 0;

        queue<int> qe;
        qe.push(id);

        while(!qe.empty())
        {
            Employee* p = memo[qe.front()];
            qe.pop();

            res += p->importance;
            for(auto x: p->subordinates)
            qe.push(x);
        }

        return res;


    }
};
