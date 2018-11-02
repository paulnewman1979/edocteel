#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
        unordered_map<string, int> mark;

        vector<string>::iterator iter;
        split(A, result);
        for (iter = result.begin(); iter != result.end(); ++iter) {
            mark[*iter]++;
        }

        result.clear();
        split(B, result);
        for (iter = result.begin(); iter != result.end(); ++iter) {
            mark[*iter]++;
        }

        result.clear();
        unordered_map<string, int>::const_iterator it = mark.begin();
        for(; it != mark.end(); ++it) {
            if (it->second == 1) {
                result.push_back(it->first);
            }
        }

        return result;
    }

private:
    void split(const string& str, vector<string>& result) {
        int start = 0;
        int end;

        while ((start < str.length() && str[start] == ' ')) ++start;

        while (start < str.length()) {
            end = str.find(" ", start);
            if (end != string::npos) {
                result.push_back(str.substr(start, end - start));
                start = end + 1;
            } else {
                result.push_back(str.substr(start));
                start = str.length();
            }
        }
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	getline(cin, a);
    getline(cin, b);
    Solution solution;
	vector<string> result = solution.uncommonFromSentences(a, b);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
