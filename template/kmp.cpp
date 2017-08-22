#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unsigned int len = s.length();
        if (0 == len) return true;

        vector<int> span;
        unsigned int i, j, k;
        span.push_back(0);
        //cout << "span " << span.size() - 1 << " " << span.back() << endl;
        for (i = 1; i < len; ++i) {
            j = i;
            k = 0;
            while ((j < len) &&
                    (s[j] == s[k])) {
                ++j; ++k;
            }
            span.push_back(j - i);
            //cout << "span " << span.size() - 1 << " " << span.back() << endl;
        }

        k = 0;
        for (i = 0; i < t.length();) {
            j = i;
            while ((j < t.length()) &&
                    (k < len) &&
                    (t[j] == s[k])) {
                ++j;
                ++k;
            }
            if (k == len) {
                return true;
            } else if (0 == k) {
                ++i;
            } else {
                //cout << "run " << k << " " << span[k - 1] << endl;
                i = j - span[k-1];
                k = span[k-1];
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	cin >> a;
	cin >> b;
    Solution solution;
	cout << (solution.isAnagram(a, b) ? "true" : "false") << endl;

    return 0;
}
