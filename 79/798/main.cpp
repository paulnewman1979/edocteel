#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& A) {
        int score = 0, maxScore = 0;
        int i, k, ret = 0;
        vector<int> scoreChange(A.size() + 1, 0);
        for (i = 0; i < A.size(); ++i) {
            if (A[i] <= i) {
                ++maxScore;
                if (A[i] > 0) {
                    k = i - A[i] + 1;
                    --scoreChange[k];
                    k = i + 1;
                    ++scoreChange[k];
                }
            } else if (A[i] < A.size()) {
                k = i + 1;
                ++scoreChange[k];
                k = A.size() - A[i] + i + 1;
                --scoreChange[k];
            }
        }
        score = maxScore;
        for (i = 1; i < A.size(); ++i) {
            score += scoreChange[i];
            if (score > maxScore) {
                maxScore = score;
                ret = i;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.bestRotation(valueVec);

    // output
    Output(ret);

    return 0;
}
