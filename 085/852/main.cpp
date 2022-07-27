#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(const vector<int>& A) {
        int start = 0;
        int end = A.size() - 1;
        int median;
        while (end > start + 2) {
            median = (start + end) / 2;
            if (A[median] > A[median + 1]) {
                end = median + 1;
            } else {
                start = median;
            }
        }
        return start + 1;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> values;
    int value;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.peakIndexInMountainArray(values) << endl;

    return 0;
}
