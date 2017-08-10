#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int i;
        int j;
        int max = 1;
        int maxs = 0;
        for (i=1; i<s.length(); ++i) {
            for (j=1; ((j<=i)&&(j+i<s.length())); ++j) {
                if (s[i-j] == s[i+j]) {
                    if (j + j + 1 > max) {
                        max = j + j + 1;
                        maxs = i - j;
                    }
                } else {
                    break;
                }
            }
            for (j=1; ((j<=i)&&(j+i-1<s.length())); ++j) {
                if (s[i-j] == s[i + j - 1]) {
                    if (j + j > max) {
                        max = j + j;
                        maxs = i - j;
                    }
                } else {
                    break;
                }
            }
        }

        return s.substr(maxs, max);
    }
};

int main(int argc, char* argv[])
{
    string value;
    cin >> value;
    Solution solution;
    cout << solution.longestPalindrome(value) << endl;
}
