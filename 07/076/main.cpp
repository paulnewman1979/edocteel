#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        std::string result;
        std::map<char, int> tMark;
        int tHitCount = 0;
        std::map<char, int> sMark;
        int i, j;

        for (i = 0; i < t.length(); ++i) {
            tMark[t[i]]++;
            tHitCount++;
        }

        i = 0;
        int hitCount = 0;
        int lenMin = s.length() + 1;
        int iMin, jMin;
        j = 0;
        while (j < s.length()) {
            while ((j < s.length()) &&
                    (hitCount < tHitCount)) {
                if (tMark.find(s[j]) != tMark.end()) {
                    sMark[s[j]]++;
                    if (sMark[s[j]] <= tMark[s[j]]) {
                        hitCount++;
                    }
                }
                ++j;
            }
            if (hitCount == tHitCount) {
                while (hitCount == tHitCount) {
                    if (tMark.find(s[i]) != tMark.end()) {
                        sMark[s[i]]--;
                        if (sMark[s[i]] < tMark[s[i]]) {
                            hitCount--;
                        }
                    }
                    ++i;
                }
                if (j - i + 1 < lenMin) {
                    iMin = i - 1;
                    jMin = j - 1;
                    lenMin = j + 1 - i;
                }
            }
        }

        if (lenMin <= s.length()) {
            result = s.substr(iMin, jMin - iMin + 1);
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
	string s;
	string t;

	cin >> s;
	cin >> t;
    Solution solution;
	cout << solution.minWindow(s, t) << endl;

    return 0;
}
