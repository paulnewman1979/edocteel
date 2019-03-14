#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<int> rec1;
    vector<int> rec2;
    int value;

    int n;
    cin >> n;
    while (n > 0) {
        cin >> value;
        rec1.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        rec2.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.isRectangleOverlap(rec1, rec2) ? "true" : "false") << endl;

    return 0;
}
