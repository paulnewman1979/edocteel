#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            result = (result << 4) +  (result << 3) + (result << 1);
            result += s[i] - '@';
        }
        return result;
	}
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);
    Solution solution;
	cout << solution.titleToNumber(str) << endl;

    return 0;
}
