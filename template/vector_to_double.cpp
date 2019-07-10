#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<string>& A) {
        double ret = 0.0;
        return ret;
    }
};

template <typename baseType>
void loadVector(vector<baseType>& valueVec) {
    int n;
    baseType value;
    cin >> n;
    while (n-- > 0) {
        cin >> value;
        valueVec.push_back(value);
    }
}

template <>
void loadVector(vector<string>& valueVec) {
    int n;
    string value;
    cin >> n;
    while (n-- > 0) {
        getline(cin, value);
        valueVec.push_back(value);
    }
}

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;

    // handle input
    loadVector(valueVec);

    // solution
    Solution solution;
    double ret = solution.largestSumOfAverages(valueVec);

    // output
    cout << ret << endl;

    return 0;
}
