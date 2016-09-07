#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > results;
		unordered_map<string, int> newStrMap;
		string newStr;
		for (int i=0; i<strs.size(); ++i) {
			newStr = strs[i];
			std::sort(newStr.begin(), newStr.end());
			unordered_map<string, int>::const_iterator iter = newStrMap.find(newStr);
			if (iter == newStrMap.end()) {
				results.push_back(vector<string>(1, strs[i]));
				newStrMap[newStr] = results.size() - 1;
			} else {
				results[iter->second].push_back(strs[i]);
			}
		}

		return results;
    }
};

int main(int argc, char* argv[])
{
	vector<string> strs;
	string str;

	cin >> str;
	while (str != "-999999") {
		strs.push_back(str);
		cin >> str;
	}

	vector< vector<string> > results;
    Solution solution;
	results = solution.groupAnagrams(strs);
	for (int i=0; i<results.size(); ++i) {
		for (int j=0; j<results[i].size(); ++j) {
			cout << results[i][j] << "\t";
		}
		cout << endl;
	}

    return 0;
}
