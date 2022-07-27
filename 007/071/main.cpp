#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		string result;
		if ((path.length() == 0) ||
			(path[0] != '/') ) {
			return string("");
		}

		vector< pair<int, int> > posVec;
		int curPos = 1;
		int pos;
		int dotCount = 0;
		int hasLetter = false;

		for (pos=1; pos<path.length(); ++pos) {
			if (path[pos] == '/') {
				if (dotCount == 1) {
				} else if (dotCount == 2) {
					if (posVec.size() > 0) {
						posVec.pop_back();
					}
				} else if (pos > curPos) {
					posVec.push_back(pair<int, int>(curPos, pos));
				}
				curPos = pos + 1;
				dotCount = 0;
				hasLetter = false;
			} else if (path[pos] == '.') {
				if (!hasLetter) {
					++ dotCount;
				}
			} else {
				hasLetter = true;
				dotCount = 0;
			}
		}

		if (path[path.length() - 1] != '/') {
			if (dotCount == 1) {
			}
			else if (dotCount == 2) {
				if (posVec.size() > 0) {
					posVec.pop_back();
				}
			} else if (pos > curPos) {
				posVec.push_back(pair<int, int>(curPos, pos));
			}
		}

		result.append("/");
		int i;
		for (i=0; i + 1 < posVec.size(); ++i) {
			curPos = posVec[i].first;
			pos = posVec[i].second;
			result.append(path.substr(curPos, pos - curPos) + "/");
		}
		if (i < posVec.size()) {
			curPos = posVec[i].first;
			pos = posVec[i].second;
			result.append(path.substr(curPos, pos - curPos));
		}

		return result;
	}
};

int main(int argc, char* argv[])
{
	string path;

	cin >> path;
	cout << path << endl;
    Solution solution;
	cout << solution.simplifyPath(path) << endl;

    return 0;
}
