#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        unordered_set<char> charCount;
        vector<int> position;
        bool hasSame = false;
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i]) {
                position.push_back(i);
                if (position.size() > 2) {
                    return false;
                }
            } else if (!hasSame) {
                if (charCount.find(A[i]) != charCount.end()) {
                    hasSame = true;
                } else {
                    charCount.insert(A[i]);
                }
            }
        }
        if (position.size() == 2) {
            if ((A[position[0]] == B[position[1]]) &&
                (A[position[1]] == B[position[0]])) {
                return true;
            }
        } else if ((position.size() == 0) &&
                hasSame) {
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	getline(std::cin, a);
	getline(std::cin, b);
    Solution solution;
    cout << (solution.buddyStrings(a, b) ? "true" : "false") << endl;

    return 0;
}
