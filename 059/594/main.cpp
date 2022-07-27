#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> count;
        unordered_map<int, int>::iterator iter;
        unordered_map<int, int>::iterator itero;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        for (iter = count.begin(); iter != count.end(); ++iter) {
            itero = count.find(iter->first + 1);
            if ((itero != count.end()) && (itero->second + iter->second > ret)) {
                ret = itero->second + iter->second;
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
    int ret = solution.findLHS(valueVec);

    // output
    Output(ret);

    return 0;
}
