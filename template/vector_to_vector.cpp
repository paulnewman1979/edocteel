#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int k;
    vector<string> words;
    vector<string> result;
    string word;

    cin >> k;
    cin >> n;
    while (n != 0) {
        cin >> word;
        words.push_back(word);
        --n;
    }
        
    Solution solution;
    result = solution.topKFrequent(words, k);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
