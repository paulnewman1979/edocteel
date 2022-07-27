#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int size = A.size();
        int i;
        if (A[0] <= A[size - 1]) {
            for (i = 0; i < size - 1; ++i) {
                if (A[i] > A[i + 1]) {
                    return false;
                }
            }
        } else {
            for (i = 0; i < size - 1; ++i) {
                if (A[i] < A[i + 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int value;
    vector<int> values;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.isMonotonic(values) ? "true" : "false") << endl;

    return 0;
}
