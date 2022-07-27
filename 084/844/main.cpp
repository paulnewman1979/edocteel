#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sDropCount = 0;
        int tDropCount = 0;
        int sIndex = S.length() - 1;
        int tIndex = T.length() - 1;
        while ((sIndex >= 0) && (tIndex >= 0)) {
            while (sIndex >= 0) {
                if (S[sIndex] == '#') {
                    sDropCount++;
                } else if (sDropCount > 0) {
                    --sDropCount;
                } else {
                    break;
                }
                --sIndex;
            }

            while (tIndex >= 0) {
                if (T[tIndex] == '#') {
                    tDropCount++;
                } else if (tDropCount > 0) {
                    --tDropCount;
                } else {
                    break;
                }
                --tIndex;
            }

            if ((sIndex >= 0) && (tIndex >= 0)) {
                if (S[sIndex] != T[tIndex]) {
                    return false;
                } else {
                    --sIndex;
                    --tIndex;
                }
            }
        }

        while (sIndex >= 0) {
            if (S[sIndex] == '#') {
                sDropCount++;
            } else if (sDropCount > 0) {
                --sDropCount;
            } else {
                break;
            }
            --sIndex;
        }

        while (tIndex >= 0) {
            if (T[tIndex] == '#') {
                tDropCount++;
            } else if (tDropCount > 0) {
                --tDropCount;
            } else {
                break;
            }
            --tIndex;
        }

        return ((sIndex < 0) && (tIndex < 0));
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	getline(cin, a);
	getline(cin, b);
    Solution solution;
    cout << (solution.backspaceCompare(a, b) ? "true" : "false") << endl;

    return 0;
}
