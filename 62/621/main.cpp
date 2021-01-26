#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        vector<int> count(26, 0);
        int charCount = 0, maxCount = 1, i, j, ret = 0, maxCountCount = 0;
        for (i = 0; i < tasks.size(); ++i) {
            j = tasks[i] - 'A';
            ++count[j];
            if (count[j] == 1) ++charCount;
            else if (count[j] > maxCount) {
                maxCount = count[j];
                maxCountCount = 1;
            } else if (count[j] == maxCount) {
                ++maxCountCount;
            }
        }
        ret = ((maxCount - 1) * (n + 1) + maxCountCount);
        if (tasks.size() > ret) ret = tasks.size();
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int n;
    vector<char> valueVec;
    Input(n);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.leastInterval(valueVec, n);

    // output
    Output(ret);

    return 0;
}
