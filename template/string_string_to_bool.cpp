#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
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
    cout << (solution.buddyStrings(a, b) ? "true" : "false") << endl;

    return 0;
}
