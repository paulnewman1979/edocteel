#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int i, j, k;
        unordered_set<string> wordSet;
        int lengthSum = 0;
        for (i = 7; i >= 1; --i) {
            for (j = 0; j < words.size(); ++j) {
                if (words[j].length() == i) {
                    if (wordSet.find(words[j]) == wordSet.end()) {
                        lengthSum += i + 1;
                        wordSet.insert(words[j]);
                        for (k = 1; k < i; ++k) {
                            wordSet.insert(words[j].substr(k));
                        }
                    }
                }
            }
        }
        return lengthSum;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<string> values;
    string value;

    cin >> n;
    getline(cin, value); // read n line
    while (n > 0) {
        getline(cin, value);
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.minimumLengthEncoding(values) << endl;

    return 0;
}
