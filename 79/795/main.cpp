#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        permutations.push_back(0);
        int ret = 0, size = A.size();
        int i = 0;
        int leftL = -1, rightL = -1, leftR = -1, rightR = -1;
        for (i = 0; i < size; ++i) {
            if (A[i] > R) {
                rightR = i;
                if (rightR - leftR > 1) {
                    ret += getPermutations(rightR - leftR - 1);
                }
                leftR = i;
                if (leftL != -1) {
                    ret -= getPermutations(rightL - leftL);
                }
                leftL = rightL = -1;
            } else if (A[i] < L) {
                if (leftL == -1) {
                    leftL = i;
                }
                rightL = i + 1;
            } else {
                if (leftL != -1) {
                    ret -= getPermutations(rightL - leftL);
                    leftL = -1;
                }
            }
        }
        if (leftR != A.size() - 1) {
            ret += getPermutations(A.size() - leftR - 1);
            if (leftL != -1) {
                ret -= getPermutations(A.size() - leftL);
            }
        }
        return ret;
    }
private:
    int getPermutations(int k) {
        if (permutations.size() <= k) {
            for (int i = permutations.size(); i <= k; ++i) {
                permutations.push_back(permutations[i - 1] + i);
            }
        }
        return permutations[k];
    }
    vector<int> permutations;
};

int main(int argc, char* argv[])
{
    // input
    int L, R;
    vector<int> valueVec;
    Input(valueVec);
    Input(L);
    Input(R);

    // solution
    Solution solution;
    int ret = solution.numSubarrayBoundedMax(valueVec, L, R);

    // output
    Output(ret);

    return 0;
}
