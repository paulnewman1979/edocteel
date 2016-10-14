#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		int gap = 'a' - 'A';
		int i = 0;
		int j = s.length() - 1;
		vector<char> inChar(256, 0);
		char ch;
		for (ch='A'; ch<='Z'; ++ ch) {
			inChar[ch] = ch + ('a' - 'A');
		}
		for (ch='a'; ch<='z'; ++ch) {
			inChar[ch] = ch;
		}
		for (ch='0'; ch<='9'; ++ch) {
			inChar[ch] = ch;
		}

		while (i < j) {
			while ((i < j) && 
				(inChar[s[i]] == 0) ) {
				++ i;
			}

			while ( (i < j) &&
				(inChar[s[j]] == 0) ) {
				-- j;
			}

			if (i == j) {
				return true;
			}
			if (inChar[s[i]] == inChar[s[j]]) {
				++ i;
				-- j;
			} else {
				return false;
			}
		}

		return true;
    }
};

int main(int argc, char* argv[])
{
	char s[1024];

	cin.getline(s, 1024);
	string str(s);
    Solution solution;
	cout << (solution.isPalindrome(s)?"true":"false") << endl;

    return 0;
}
