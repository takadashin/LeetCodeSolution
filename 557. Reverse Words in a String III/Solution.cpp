class Solution {
public:
    string reverseWords(string s) {
    string res = "";
    auto x = s.begin();
    for (auto i = s.begin(); i < s.end(); i++)
    {
        if (*i == ' ')
        {
            reverse(x, i);
            x = i + 1;
        }
    }
    reverse(x, s.end());

    return s;
}
};
