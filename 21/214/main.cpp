#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        map<char, int> charMap;
        map<char, int>::iterator iter;
        string result;
        int i, j;
        int singleCount = 0;
        for (i = 0; i < s.length(); ++i) {
            iter = charMap.find(s[i]);
            if (iter != charMap.end()) {
                iter->second++;
            } else {
                charMap[s[i]] = 1;
            }
        }

        iter = charMap.begin();
        while (iter != charMap.end()) {
            if (iter->second % 2 == 1) {
                ++singleCount;
            }
            ++iter;
        }

        j = s.length() - 1;
        while (j > 0) {
            if (singleCount < 2) {
                if (checkValid(s, 0, j)) {
                    break;
                }
            }
            result += s[j];
            --charMap[s[j]];
            if (charMap[s[j]] % 2 == 0) {
                --singleCount;
            } else {
                ++singleCount;
            }
            --j;
        }

        result.append(s);

        return result;
	}

private:
    bool checkValid(string s, int i, int j) {
        int l = i;
        int m = j;
        while (l < m) {
            if (s[l] != s[m]) {
                return false;
            }
            ++l;
            --m;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);
    Solution solution;
	cout << solution.shortestPalindrome(str) << endl;

    return 0;
}
