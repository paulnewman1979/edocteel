#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		if (0 == a.length()) {
			return b;
		} else if (0 == b.length()) {
			return a;
		}

		string result;
		int i = 1;
		int j;
		int aSize = a.length();
		int bSize = b.length();
		int increment = 0;
		int aCur;
		int bCur;
		while ((i<=aSize) || (i<=bSize)) {
			if (i<=aSize) {
				aCur = (a[aSize -i] == '0')?0:1;
			} else {
				aCur = 0;
			}

			if (i<=bSize) {
				bCur = (b[bSize -i] == '0')?0:1;
			} else {
				bCur = 0;
			}

			result += ((aCur + bCur + increment)%2)?"1":"0";
			increment = (aCur + bCur + increment >= 2)?1:0;

			++ i;
		}
		if (increment == 1) {
			result += "1";
		}

		i = 0;
		j = result.length() - 1;
		char ch;
		while (i < j) {
			ch = result[i];
			result[i] = result[j];
			result[j] = ch;

			++ i;
			-- j;
		}

		return result;
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	cin >> a;
	cin >> b;
    Solution solution;
	cout << solution.addBinary(a, b) << endl;

    return 0;
}
