#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int max = 0;
        int trend = 0;
        int start = 0;
        int cur = 1;

        while (cur < A.size()) {
            if (A[cur] > A[cur - 1]) {
                switch(trend) {
                case 0:
                    start = cur - 1;
                    trend = 1;
                    break;
                case 1:
                    break;
                default:
                    if (cur - start > max) {
                        max = cur - start;
                    }
                    start = cur - 1;
                    trend = 1;
                }
            } else if (A[cur] < A[cur - 1]) {
                switch(trend) {
                case 0:
                    break;
                case 1:
                    trend = 2;
                    break;
                default:
                    trend = 2;
                }
            } else {
                switch(trend) {
                case 0:
                    break;
                case 1:
                    trend = 0;
                    break;
                default:
                    if (cur - start > max) {
                        max = cur - start;
                    }
                    trend = 0;
                }
            }
            ++cur;
        }

        if ((trend == 2) && (cur - start > max)) {
            max = cur - start;
        }
        return max;
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
    cout << solution.longestMountain(values) << endl;

    return 0;
}
