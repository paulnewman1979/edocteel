#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        int j = s.length() - 1;
        int k;
        char ch;

        // remove space
        ch = ' ';
        i = 0;
        j = 0;
        while (i < s.length()) {
            if ((s[i] != ' ') || (ch != ' ')) {
                s[j] = s[i];
                ch = s[j];
                ++j;
            }
            ++i;
        }
        while ((j > 0) && (s[j - 1] == ' ')) {
            --j;
        }
        s.erase(j);

        // reverse string
        i = 0;
        j = s.length() - 1;
        while (i < j) {
            ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            ++i;
            --j;
        }

        // reverse word
        i = 0;
        while (i < s.length()) {
            j = i + 1;
            while ((j < s.length()) && (s[j] != ' ')) {
                ++j;
            }
            k = j - 1;
            while (i < k) {
                ch = s[i];
                s[i] = s[k];
                s[k] = ch;
                ++i;
                --k;
            }
            i = j + 1;
        }
    }
};

int main(int argc, char* argv[])
{
	string s;

    getline(std::cin, s);
    Solution solution;
	solution.reverseWords(s);
	cout << s << endl;

    return 0;
}
