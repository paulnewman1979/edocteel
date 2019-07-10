#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string result;
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    string value;
    string paragraph;
    vector<string> banned;

    getline(std::cin, paragraph);
    cin >> n;
    while (n > 0) {
        getline(std::cin, value);
        banned.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.mostCommonWord(paragraph, banned) << endl;

    return 0;
}
