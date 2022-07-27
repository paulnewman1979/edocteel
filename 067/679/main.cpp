#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<int> marks(4, 0);
        vector<pair<int, int>> rets;
        int i, j, k;
        for (i = 0; i < 4; ++i) {
            marks[i] = 1;

            rets.clear();
            rets.push_back(make_pair(1, 24 - nums[i]));  // +
            rets.push_back(make_pair(1, 24 + nums[i]));  // -
            rets.push_back(make_pair(1, nums[i] - 24));  // -
            rets.push_back(make_pair(nums[i], 24));      // *
            rets.push_back(make_pair(1, 24 * nums[i]));  // /
            rets.push_back(make_pair(24, nums[i]));      // /

            if (check3(nums, marks, rets)) return true;

            marks[i] = 0;
        }

        marks[0] = 1;
        for (i = 1; i < 4; ++i) {
            marks[i] = 1;
            possible2(nums, marks, rets);

            for (j = 0; j < 4; ++j) marks[j] = 1 - marks[j];
            vector<pair<int, int>> nrets;
            possible2(nums, marks, nrets);
            for (j = 0; j < rets.size(); ++j) {
                for (k = 0; k < nrets.size(); ++k) {
                    if (rets[j].second * nrets[k].second == rets[j].first * nrets[k].first * 24) return true;
                }
            }
            for (j = 0; j < 4; ++j) marks[j] = 1 - marks[j];

            marks[i] = 0;
        }
        return false;
    }

private:
    void possible2(const vector<int>& nums,
            vector<int>& marks,
            vector<pair<int, int>>& rets) {
        rets.clear();
        for (int i = 0; i < 4; ++i) {
            if (marks[i] == 0) {
                for (int j = i + 1; j < 4; ++j) {
                    if (marks[j] == 0) {
                        rets.push_back(make_pair(1, nums[i] + nums[j]));     // +
                        rets.push_back(make_pair(1, nums[i] - nums[j]));     // -
                        rets.push_back(make_pair(1, nums[j] - nums[i]));     // -
                        rets.push_back(make_pair(1, nums[i] * nums[j]));     // *
                        rets.push_back(make_pair(nums[i], nums[j]));         // /
                        rets.push_back(make_pair(nums[j], nums[i]));         // /
                    }
                }
            }
        }
    }

    bool check3(const vector<int>& nums,
            vector<int>& marks,
            const vector<pair<int, int>>& rets) {
        vector<pair<int, int>> nrets;
        vector<pair<int, int>> erets;
        int i, j, k;
        for (i = 0; i < 4; ++i) {
            if (marks[i] == 0) {
                marks[i] = 1;
                erets.clear();
                possible2(nums, marks, erets);

                nrets.clear();
                for (j = 0; j < rets.size(); ++j) {
                    nrets.push_back(make_pair(rets[j].first, rets[j].second - rets[j].first * nums[i]));
                    nrets.push_back(make_pair(rets[j].first, rets[j].second + rets[j].first * nums[i]));
                    nrets.push_back(make_pair(rets[j].first, rets[j].first * nums[i] - rets[j].second));
                    nrets.push_back(make_pair(rets[j].first * nums[i], rets[j].second));
                    nrets.push_back(make_pair(rets[j].first, rets[j].second * nums[i]));
                    nrets.push_back(make_pair(rets[j].second, rets[j].first * nums[i]));
                }

                for (j = 0; j < nrets.size(); ++j) {
                    for (k = 0; k < erets.size(); ++k) {
                        if (nrets[j].first * erets[k].second == nrets[j].second * erets[k].first) return true;
                    }
                }

                marks[i] = 0;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.judgePoint24(valueVec);

    // output
    Output(ret);

    return 0;
}
