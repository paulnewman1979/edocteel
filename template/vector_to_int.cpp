#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int result = 0;
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<string> ops;
    string op;

    cin >> n;
    while (n > 0) {
        cin >> op;
        ops.push_back(op);
        cin >> n;
    }
        
    Solution solution;
    cout << solution.calPoints(ops) << endl;

    return 0;
}
