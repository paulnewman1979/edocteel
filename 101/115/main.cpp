#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
		int si = 0;
		int ti = 0;

		int i, j;
		//vector< vector<int> > ways(s.length() + 1, vector<int>(t.length() + 1, -1));
		vector< vector<int> > ways;
		vector<int> way(t.length() + 1, -1);
		for (i=0; i<=s.length(); ++i) {
			ways.push_back(way);
		}

		return numDistinct(s, t, si, ti, ways);
    }

	int numDistinct(const string& s, const string& t, const int si, const int ti, vector< vector<int> >& ways) {
		if (ways[si][ti] != -1) {
			return ways[si][ti];
		} else if (ti >= t.length()) {
			ways[si][ti] = 1;
			return 1;
		} else if (si >= s.length()) {
			ways[si][ti] = 0;
			return 0;
		} else if (s[si] == t[ti]) {
			ways[si][ti] = numDistinct(s, t, si + 1, ti + 1, ways) + numDistinct(s, t, si + 1, ti, ways);
			return ways[si][ti];
		} else {
			ways[si][ti] = numDistinct(s, t, si + 1, ti, ways);
			return ways[si][ti];
		}
	}
};

int main(int argc, char* argv[]) {
	string s;
	string t;

	cin >> s;
	cin >> t;

	cout << s << endl;
	cout << t << endl;

	Solution solution;
	cout << solution.numDistinct(s, t) << endl;

	return 0;
}
