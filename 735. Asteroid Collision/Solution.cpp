class Solution {
public:
    

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> checker;

    
    for(auto x: asteroids)
    {
        while(!checker.empty() && checker.top() > 0 && checker.top() < -x)
        checker.pop();
        if(checker.empty() || checker.top() < 0 || x > 0)
        checker.push(x);
        else if(checker.top() == -x) checker.pop();

    }
    vector<int> res;
    while(!checker.empty())
    res.insert(res.begin(),checker.top()),checker.pop();
    return res;
}
};
