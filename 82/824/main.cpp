#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

static const std::string STRING_MA("ma");
static const char CHAR_A('a');
static const string STRING_SPACE(" ");

class Solution {
public:
    string toGoatLatin(string S) {
        int wordIndex = 1;
        int i;
        bool isVowel = false;
        int vowelPos = 0;
        string result;

        vowelPos = 0;
        for (i = 0; i < S.length(); ++i) {
            if (i == vowelPos) {
                switch(S[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    isVowel = true;
                    result.append(1, S[i]);
                    break;
                case ' ':
                    ++vowelPos;
                    break;
                default:
                    isVowel = false;
                    vowelPos = i;
                }
            } else if (S[i] == ' ') {
                if (!isVowel) {
                    result.append(1, S[vowelPos]);
                }
                result.append(STRING_MA);
                result.append(wordIndex, CHAR_A);
                result.append(STRING_SPACE);
                vowelPos = i + 1;
                ++wordIndex;
            } else {
                result.append(1, S[i]);
            }
        }

        if (i != vowelPos) {
            if (!isVowel) {
                result.append(1, S[vowelPos]);
            }
            result.append(STRING_MA);
            result.append(wordIndex, CHAR_A);
        }

        return result;
	}
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);
    Solution solution;
	cout << solution.toGoatLatin(str) << endl;

    return 0;
}
