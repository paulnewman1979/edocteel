#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int i = 0;
		int status = 0;
		for (i=0; i<s.length(); ++i) {
			switch(s[i])
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if ((0 == status) ||
					(1 == status) ||
					(2 == status)) {
					status = 2;
				} else if ((3 == status) ||
					(4 == status) ) {
					status = 4;
				} else if ((5 == status) ||
					(6 == status) ||
					(7 == status)) {
					status = 7;
				} else {
					return false;
				}
				break;

			case '-':
				if ((0 == status) ||
					(5 == status) ) {
					++ status;
				} else {
					return false;
				}
				break;
			case 'e':
				if ((2 == status) ||
					(3 == status) ||
					(4 == status) ) {
					status = 5;
				} else {
					return false;
				}
				break;
			case '.':
				if ((0 == status) ||
					(1 == status) ||
					(2 == status) ) {
					status = 3;
				} else {
					return false;
				}
				break;
			case ' ':
				if ((0 == status) || 
					(8 == status) ) {
				} else if (7 == status) {
					status = 8;
				} else {
					return false;
				}
				break;

			default:
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
	cout << (solution.isNumber(str)?1:0) << endl;

    return 0;
}
