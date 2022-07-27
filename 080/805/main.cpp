
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        if (A.size() < 2) return false;
        double average = 0.0;
        double newSum = 0;
        for (auto a : A) average += a;
        average /= A.size();
        if (A[0] == average) return true;

        vector<unordered_set<int>> sums(31);
        sums[0].insert(0);
        sums[1].insert(A[1]);
        int i;
        for (i = 1; i < A.size() - 1; ++i) {
            for (int j = i; j >= 0; --j) {
                for (auto p : sums[j]) {
                    newSum = p + A[i];
                    if (newSum / (j + 1) == average) return true;
                    sums[j + 1].insert(newSum);
                }
            }
        }

        for (int j = i - 1; j >= 0; --j) {
            for (auto p : sums[j]) {
                newSum = p + A[i];
                if (newSum / (j + 1) == average) return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> values;
    Input(values);

    // solution
    Solution solution;
    bool ret = solution.splitArraySameAverage(values);

    // output
    Output(ret);

    return 0;
}
