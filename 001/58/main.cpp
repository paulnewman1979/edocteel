#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		int count = 0;
		bool start = false;
		for (int i=s.length()-1; i>=0; --i) {
			if (s[i] != ' ') {
				++ count;
				start = true;
			} else {
				if (start) {
					break;
				}
			}
		}
		return count;
    }
};

int main(int argc, char* argv[])
{
	string str;

	cin >> str;
	cout << str << endl;
    Solution solution;
	cout << solution.lengthOfLastWord(str) << endl;

    return 0;
}
