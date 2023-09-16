class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
    vector<int> original(26, 0);
    vector<int> temp(26, 0);
    for (int i = 0; i < s1.size(); i++)
    {
        original[s1[i] - 'a']++;
        temp[s2[i] - 'a']++;
    }
    int j;
    for (int i = 0; i <= s2.size() - s1.size(); i++)
    {

        if(temp == original) return true;
        if (i + s1.size() < s2.size())
        {
        temp[s2[i + s1.size()] - 'a']++;
        temp[s2[i] - 'a']--;
        }
    }
    return false;
}
};
