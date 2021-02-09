#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxPath = 0, path = 0, i, j, size = nums.size();
        vector<int> marks(size, 1);
        for (i = 0; i < size; ++i) {
            if (marks[i] == 1) {
                marks[i] = 0;
                path = 1;
                j = nums[i];
                while (j != i) {
                    ++path;
                    marks[j] = 0;
                    j = nums[j];
                }
                if (path > size / 2) return path;
                if (path > maxPath) maxPath = path;
            }
        }
        return maxPath;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.arrayNesting(valueVec);

    // output
    Output(ret);

    return 0;
}
