class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res;
        int distance = INT_MAX;
        for(auto x: letters)
        {
            if(x - target > 0 &&  x - target  < distance)
            {
                distance = abs(target - x);
                res = x;
            }
        }
        return distance == INT_MAX ? letters[0]: res;
    }
};
