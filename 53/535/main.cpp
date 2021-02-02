#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

static const vector<char> CharSet({
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U',
    'V', 'W', 'X', 'Y', 'Z', '@', '$'
});

static const string prefix("http://tinyurl.com/");

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
		int num = rand() & 0x3fffffff;
        while (urlMap.find(num) != urlMap.end()) {
            num = rand() & 0x3fffffff;
        }
        urlMap[num] = longUrl;
        string shortUrl = prefix + "00000";
        int i = shortUrl.length() - 1;
        while (num > 0) {
            shortUrl[i] = CharSet[num & 0x3f];
            --i;
            num = (num>>6);
        }
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int num = 0;
        for (int i = prefix.length(); i < prefix.length() + 5; ++i) {
            if ((shortUrl[i] >= '0') && (shortUrl[i] <= '9')) {
                num = (num<<6) + (shortUrl[i] - '0');
            } else if ((shortUrl[i] >= 'a') && (shortUrl[i] <= 'z')) {
                num = (num<<6) + (shortUrl[i] - 'a') + 10;
            } else if ((shortUrl[i] >= 'A') && (shortUrl[i] <= 'Z')) {
                num = (num<<6) + (shortUrl[i] - 'A') + 36;
            } else if (shortUrl[i] == '@') {
                num = (num<<6) + 62;
            } else {
                num = (num<<6) + 63;
            }
        }

        unordered_map<int, string>::const_iterator iter = urlMap.find(num);
        return (iter != urlMap.end()) ? iter->second : "";
    }

private:
	unordered_map<int, string> urlMap;
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<string>> actions;
    Input(actions);

    // solution
    unordered_map<string, string> records;
    Solution solution;
    string ret;
    for (const auto& action : actions) {
        if (action[0] == "encode") {
            ret = solution.encode(action[1]);
            records[action[1]] = ret;
        } else {
            ret = solution.decode(records[action[1]]);
            Output(ret);
        }
    }

    return 0;
}
