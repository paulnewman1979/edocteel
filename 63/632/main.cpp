#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <algorithm>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool minComp(pair<int, int>& a, pair<int, int>& b) {
    return (b.first < a.first);
}

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ret(2);
        vector<int> listIndex(nums.size(), 0);
        vector<pair<int, int>> minHeap;
        int i, minRange, curMax, index;
        ret[0] = nums[0][0];
        ret[1] = nums[0][0];
        minHeap.push_back(make_pair(nums[0][0], 0));
        for (i = 1; i < nums.size(); ++i) {
            minHeap.push_back(make_pair(nums[i][0], i));
            if (nums[i][0] < ret[0]) ret[0] = nums[i][0];
            else if (nums[i][0] > ret[1]) ret[1] = nums[i][0];
        }
        minRange = ret[1] - ret[0];
        curMax = ret[1];
        make_heap(minHeap.begin(), minHeap.end(), minComp);
        pop_heap(minHeap.begin(), minHeap.end(), minComp);
        while (true) {
            index = minHeap.back().second;
            minHeap.pop_back();
            ++listIndex[index];
            if (listIndex[index] >= nums[index].size()) break;
            else {
                i = nums[index][listIndex[index]];
                minHeap.push_back(make_pair(i, index));
                if (i > curMax) curMax = i;
                push_heap(minHeap.begin(), minHeap.end(), minComp);
                pop_heap(minHeap.begin(), minHeap.end(), minComp);
                if (curMax - minHeap.back().first < minRange) {
                    minRange = curMax - minHeap.back().first;
                    ret[0] = minHeap.back().first;
                    ret[1] = curMax;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    vector<int> retVec = solution.smallestRange(valueGrid);

    // output
    Output(retVec);

    return 0;
}

