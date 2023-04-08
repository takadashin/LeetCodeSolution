class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
    auto find1 = num1.find('+');
    auto find2 = num2.find('+');

    int n1f = stoi(num1.substr(0, find1));
    int n1s = stoi(num1.substr( find1+1));

    int n2f = stoi(num2.substr(0, find2));
    int n2s = stoi(num2.substr(find2 + 1, num2.size() - 2 - find2));

    int noni = n1f * n2f + n1s * n2s * -1;;
    int iy = n1f * n2s + n1s * n2f;
    

    return to_string(noni) + "+" + to_string(iy)+ "i";
}
};
