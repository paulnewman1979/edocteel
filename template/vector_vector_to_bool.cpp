#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool possibleBipartition(vector<vector<int> >& dislikes) {
        return true;
    }
};

int main(int argc, char* argv[])
{
    vector< vector<int> > lines;

    int n;
    int n1;
    int value;
    vector<int> line;

    cin >> n;
    while (n > 0) {
        cin >> n1;
        line.clear();
        while (n1 > 0) {
            cin >> value;
            line.push_back(value);
            --n1;
        }
        lines.push_back(line);
        --n;
    }

    Solution solution;
    cout << (solution.possibleBipartition(lines) ? "true" : "false") << endl;

    return 0;
}
