#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
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
	vector<string> result = solution.uncommonFromSentences(a, b);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
