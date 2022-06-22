#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] > b[0];
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        int size1 = nums1.size(), size2 = nums2.size(), i, numPos1, numPos2;
        vector<vector<int>> sumHeap;
        for (i = 0; i < size2; ++i) {
            sumHeap.push_back(vector<int>{nums1[0] + nums2[i], 0, i});
        }
        make_heap(sumHeap.begin(), sumHeap.end(), compare);
        i = 0;
        while ((i < k) && (sumHeap.size() > 0)) {
            pop_heap(sumHeap.begin(), sumHeap.end(), compare);
            numPos1 = sumHeap.back()[1];
            numPos2 = sumHeap.back()[2];
            ret.push_back(vector<int>{nums1[numPos1], nums2[numPos2]});
            sumHeap.pop_back();
            if (numPos1 + 1 < size1) {
                sumHeap.push_back(vector<int>{nums1[numPos1 + 1] + nums2[numPos2], numPos1 + 1, numPos2});
                push_heap(sumHeap.begin(), sumHeap.end(), compare);
            }
            ++i;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int k;
    vector<int> nums1;
    vector<int> nums2;
    Input(k);
    Input(nums1);
    Input(nums2);

    // solution
    Solution solution;
    vector<vector<int>> ret = solution.kSmallestPairs(nums1, nums2, k);

    // output
    Output(ret);

    return 0;
}
