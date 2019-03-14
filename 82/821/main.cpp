#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> results(S.length(), S.length());
        int i;
        bool foundC = false;
        if (S[0] == C) {
            results[0] = 0;
            foundC = true;
        }
        for (i = 1; i < S.length(); ++i) {
            if (S[i] == C) {
                results[i] = 0;
                foundC = true;
            } else if (foundC) {
                results[i] = results[i - 1] + 1;
            }
        }

        foundC = false;
        i = S.length() - 1;
        if (S[i] == C) {
            results[i] = 0;
            foundC = true;
        }
        --i;
        for (; i >= 0; --i) {
            if (S[i] == C) {
                results[i] = 0;
                foundC = true;
            } else if (foundC) {
                if (results[i + 1] + 1 < results[i]) {
                    results[i] = results[i + 1] + 1;
                }
            }
        } 
        return results;
	}
};

int main(int argc, char* argv[])
{
    // parameters
    char C;
    string str;

    // init
    cin >> C;
    getline(std::cin, str); // read C line
	getline(std::cin, str);

    Solution solution;
    vector<int> results = solution.shortestToChar(str, C);
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << std::endl;
    }

    return 0;
}
