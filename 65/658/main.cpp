#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ret(k, 0);
        int i, j;
        if (x <= arr[0]) {
            for (i = 0; i < k; ++i) {
                ret[i] = arr[i];
            }
        } else if (x > arr.back()) {
            j = k - 1;
            for (i = arr.size() - 1, j = k - 1; j >= 0; --i, --j) {
                ret[j] = arr[i];
            }
        } else {
            int min = 0, max = arr.size(), mid;
            while (min + 1 < max) {
                mid = (min + max) / 2;
                if (x < arr[mid]) {
                    max = mid;
                } else if (x > arr[mid]) {
                    min = mid;
                } else {
                    min = mid;
                    max = mid + 1;
                }
            }
            for (i = 0; i < k; ++i) {
                if (min == -1) {
                    ++max;
                } else if (max == arr.size()) {
                    --min;
                } else if (x - arr[min] <= arr[max] - x) {
                    --min;
                } else {
                    ++max;
                }
            }
            ++min;
            for (i = min, j = 0; i < max; ++i, ++j) {
                ret[j] = arr[i];
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int k, x;
    vector<int> words;
    Input(k);
    Input(x);
    Input(words);

    // solution
    Solution solution;
    vector<int> ret = solution.findClosestElements(words, k, x);

    // output
    Output(ret);

    return 0;
}
