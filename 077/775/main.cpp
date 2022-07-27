#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            if ((A[i] != i) && (A[i] - i != 1) && (i - A[i] != 1)) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.isIdealPermutation(valueVec);

    // output
    Output(ret);

    return 0;
}
