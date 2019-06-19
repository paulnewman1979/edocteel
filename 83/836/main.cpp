#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long int a, b;
        a = rec1[0] - rec2[2];
        a *= rec2[0] - rec1[2];
        b = rec1[1] - rec2[3];
        b *= rec2[1] - rec1[3];
        return ((a > 0) && (b > 0));
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
