#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

static const int64_t MODULO = 1000000007;

class Solution {
public:
    int uniqueLetterString(string S) {
        int64_t count = 0;
        int i, j, m, n;
        int size;
        vector<vector<int> > pos(26);
        for (i = 0; i < 26; ++i) {
            pos[i].push_back(-1);
        }
        for (i = 0; i < S.length(); ++i) {
            pos[S[i] - 'A'].push_back(i);
        }
        for (i = 0; i < 26; ++i) {
            pos[i].push_back(S.length());
        }

        for (i = 0; i < 26; ++i) {
            size = pos[i].size();
            if (size > 2) {
                for (j = 1; j < size - 1; ++j) {
                    m = pos[i][j] - pos[i][j - 1];
                    n = pos[i][j + 1] - pos[i][j];
                    count += m * n;
                }
            }
            count %= MODULO;
        }

        return count;
	}
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);
    Solution solution;
	cout << solution.uniqueLetterString(str) << endl;

    return 0;
}
