#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

static const char CHAR_STAR('*');

class Solution {
public:
    string maskPII(string S) {
        string result;
        if (((S[0] >= 'a') && (S[0] <= 'z')) ||
                ((S[0] >= 'A') && (S[0] <= 'Z'))) {
            maskEmail(S, result);
        } else {
            maskPhone(S, result);
        }
        return result;
	}

private:
    inline char lowerChar(char ch) {
        return ((ch >= 'A') && (ch <= 'Z')) ? (ch - 'A' + 'a') : ch;
    }

    void maskEmail(const string& S, string& result) {
        int i = 0;
        int status = 0;
        for (i = 0; i < S.length(); ++i) {
            switch(S[i]) {
            case '@':
                result += lowerChar(S[i - 1]);
                result += S[i];
                status = 2;
                break;
            case '.':
                result += S[i];
                break;
            default:
                switch(status) {
                case 0:
                    result += lowerChar(S[i]);
                    result.append("*****");
                    status = 1;
                    break;
                case 1:
                    break;
                default:
                    result += lowerChar(S[i]);
                    break;
                }
            }
        }
    }

    void maskPhone(const string& S, string& result) {
        vector<char> pos;
        int count = 0;
        int i;
        for (i = S.length() - 1; i >= 0; --i) {
            if ((S[i] >= '0') && (S[i] <= '9')) {
                if (count < 4) {
                    pos.push_back(S[i]);
                } else if (count >= 10) {
                    pos.push_back(S[i]);
                }
                ++count;
            }
        }

        if (pos.size() > 4) {
            result.append("+");
            result.append(pos.size() - 4, CHAR_STAR);
            result.append("-");
        }
        result.append("***-***-");
        for (i = 3; i >= 0; --i) {
            result.append(1, pos[i]);
        }
    }
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);
    Solution solution;
	cout << solution.maskPII(str) << endl;

    return 0;
}
