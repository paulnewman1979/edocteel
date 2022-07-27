#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int i, j;
        unordered_set<string> keySet;
        map<char, int>::const_iterator iter;
        for (i = 0; i < A.size(); ++i) {
            stringstream oss;
            map<char, int> charMap0;
            map<char, int> charMap1;
            for (j = 0; j < A[i].length(); j += 2) {
                charMap0[A[i][j]]++;
            }
            for (j = 1; j < A[i].length(); j += 2) {
                charMap1[A[i][j]]++;
            }
            iter = charMap0.begin();
            while (iter != charMap0.end()) {
                oss << iter->first << iter->second;
                ++iter;
            }
            oss << ":";
            iter = charMap1.begin();
            while (iter != charMap1.end()) {
                oss << iter->first << iter->second;
                ++iter;
            }

            keySet.insert(oss.str());
        }
        return keySet.size();
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<string> values;
    string value;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.numSpecialEquivGroups(values) << endl;

    return 0;
}
