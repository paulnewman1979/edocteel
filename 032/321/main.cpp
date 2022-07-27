#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;
        for(int i = max(0, k-n); i <= min(k, m); ++i){
            res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k-i)));
        }
        return res;
    }

    vector<int> maxVector(vector<int> nums, int k){
        int drop = nums.size() - k;
        vector<int> res;
        for (int num : nums) {
            while (drop && res.size() && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    vector<int> mergeVector(vector<int> nums1, vector<int> nums2){
        vector<int> res;
        while (nums1.size() + nums2.size()) {
            vector<int> &tmp = nums1 > nums2 ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
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
    vector<int> ret = solution.maxNumber(nums1, nums2, k);

    // output
    Output(ret);

    return 0;
}
