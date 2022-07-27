#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<int> A(2000, 0);
        vector<int> B(2000, 0);
        int i;
        for (i = 0; i < fronts.size(); ++i) {
            if (fronts[i] == backs[i]) {
                B[fronts[i] - 1] = 1;
            } else {
                A[fronts[i] - 1] = 1;
                A[backs[i] - 1] = 1; 
            }
        }

        for (i = 0; i < 2000; ++i) {
            if ((A[i] > 0) && (B[i] == 0)) {
                return i + 1;
            }
        }
        return 0;
    }
};

int main(int argc, char* argv[])
{
    vector<int> fronts;
    vector<int> backs;
    int value;

    int n;
    cin >> n;
    while (n > 0) {
        cin >> value;
        fronts.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        backs.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.flipgame(fronts, backs) << endl;

    return 0;
}
