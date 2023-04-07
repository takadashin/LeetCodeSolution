class Solution {
private:
    const string acnii = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string, string> codeurl, urlcode;
   
    const string de_str = "http://tinyurl.com/";
public:

    // Encodes a URL to a shortened URL.
    vector<string> urlmemo;
    string encode(string longUrl) {
        string code;
        if (!urlcode.count(longUrl))
        {
            for (int i = 0; i < 6; i++)
                code.push_back(acnii[rand() % acnii.size()]);
            urlcode[longUrl] = code;
            codeurl[ code] = longUrl;
            return de_str + code;
        }
        else
            return de_str + urlcode[longUrl];
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortUrl.size() != 25 || !codeurl.count(shortUrl.substr(19)))
            return "";
        return codeurl[shortUrl.substr(19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
