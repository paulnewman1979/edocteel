#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> results;
        return results;
	}
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);

    Solution solution;
    vector<int> results = solution.splitIntoFibonacci(str);
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
