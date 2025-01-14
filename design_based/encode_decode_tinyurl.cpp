// Problem Link: https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
public:
    unordered_map<long long, string> codeToUrl;
    unordered_map<string, long long> urlToCode;

    long long computeCode(string url) {
        long long code = 1;
        for (int i = 1; i <= url.size(); i++) {
            code = code + url[i - 1] * i;
        }
        return code;
    }

    string convertToTitle(long long num) {
        string res = "";
        while (num > 0) {
            int rem = (num - 1) % 26;
            res = string(1, 'A' + rem) + res;
            num = (num - 1) / 26;
        }
        return res;
    }

    string encode(string longUrl) {
        if (urlToCode.find(longUrl) != urlToCode.end()) {
            long long code = urlToCode[longUrl];
            return "https://tinyurl.com/" + convertToTitle(code);
        }

        long long code = computeCode(longUrl);
        string shortUrlPart = convertToTitle(code);

        codeToUrl[code] = longUrl;
        urlToCode[longUrl] = code;

        return "https://tinyurl.com/" + shortUrlPart;
    }

    string decode(string shortUrl) {
        string codePart = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        long long code = 0;

        for (char c : codePart) {
            code = code * 26 + (c - 'A' + 1);
        }

        if (codeToUrl.find(code) != codeToUrl.end()) {
            return codeToUrl[code];
        }
        return "";
    }
};
