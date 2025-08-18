class Solution {
public:
    string maskPII(string s) {
        int los = s.find('@');
        string res = "";
        if(los == string::npos) // not email => phone
        {
            string temp = "";
            for(auto x: s)
            if(isdigit(x)) temp += x;
            int len = temp.size();
            if(len == 13) res += "+***-***-***-";
            else  if(len == 12)  res += "+**-***-***-";
            else  if(len == 11)  res += "+*-***-***-";
            else  res += "***-***-";

            res += temp.substr(temp.size()-4);

        }
        else
        {
            transform(s.begin(),s.end(),s.begin(), ::tolower);
            res = s.substr(0,1) + "*****" + s.substr(los-1);

        }

        return res;

    }
};
