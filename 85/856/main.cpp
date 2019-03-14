#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string& S) {
        int pos = 0;
        int result = scoreOfParentheses(S, pos);
        while (pos < S.length()) {
            result += scoreOfParentheses(S, pos);
        }
        return result;
	}

private:
    int scoreOfParentheses(string& S, int& pos) {
        int result = 0;
        ++pos;
        if (S[pos] == ')') {
            ++pos;
            return 1;
        }
        while (S[pos] != ')') {
            result += scoreOfParentheses(S, pos);
        }
        result += result;
        ++pos;
        return result;
    }
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);
    Solution solution;
	cout << solution.scoreOfParentheses(str) << endl;

    return 0;
}
