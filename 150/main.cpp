#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		vector<int> result;
		int value1;
		int value2;
		for (int i=0; i<tokens.size(); ++i) {
			if (tokens[i] == "+") {
				value1 = result.back();
				result.pop_back();
				value2 = result.back();
				result.pop_back();
				result.push_back(value2 + value1);
			} else if (tokens[i] == "-") {
				value1 = result.back();
				result.pop_back();
				value2 = result.back();
				result.pop_back();
				result.push_back(value2 - value1);
			} else if (tokens[i] == "*") { 
				value1 = result.back();
				result.pop_back();
				value2 = result.back();
				result.pop_back();
				result.push_back(value2 * value1);
			} else if (tokens[i] == "/") {
				value1 = result.back();
				result.pop_back();
				value2 = result.back();
				result.pop_back();
				result.push_back(value2 / value1);
			} else {
				result.push_back(strtol(tokens[i].c_str(), NULL, 10));
			}
		}

		return result[0];
    }
};

int main(int argc, char* argv[])
{
	vector<string> tokens;
	string str;

	cin >> str;
	while (str != "-999999") {
		tokens.push_back(str);
		cin >> str;
	}

    Solution solution;
	cout << solution.evalRPN(tokens) << endl;

    return 0;
}
