#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		std::vector<int> ms(256, -1);
		std::vector<int> ts(256, -1);

		if (s.length() != t.length()) {
			return false;
		}
		int i;
		int mscount = 0;
		int tscount = 0;
		for (i=0; i<s.length(); ++i) {
			if (ms[s[i]] == -1) {
				ms[s[i]] = mscount;
				mscount++;
			}
			if (ts[t[i]] == -1) {
				ts[t[i]] = tscount;
				tscount++;
			}

			if (ms[s[i]] != ts[t[i]]) {
				std::cout << ms[s[i]] << " " << ts[t[i]] << std::endl;
				return false;
			}
		}

		return true;
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	cin >> a;
	cin >> b;
    Solution solution;
	cout << (solution.isIsomorphic(a, b)?"true":"false") << endl;

    return 0;
}
