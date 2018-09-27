#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        return 0;
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
