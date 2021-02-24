#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int lv, hv, i;
        multiset<int, greater<>> lower;
        multiset<int, greater<>>::iterator lIter;
        multiset<int> higher;
        multiset<int>::iterator hIter;
        vector<double> ret;

        switch(k) {
        case 1:
            for (i = 0; i < nums.size(); ++i) {
                ret.push_back(nums[i]);
            }
            break;
        case 2:
            for (i = 0; i < nums.size() - 1; ++i) {
                ret.push_back(((long long int)nums[i] + nums[i + 1]) / 2.0);
            }
            break;
        default:
            for (i = 0; i < k; ++i) {
                lower.insert(nums[i]);
                if (lower.size() > (k + 1) / 2) {
                    lIter = lower.begin();
                    higher.insert(*lIter);
                    lower.erase(lIter);
                }
            }
            if (k % 2 == 1) {
                lIter = lower.begin(); lv = *lIter; lower.erase(lIter);
                ret.push_back(lv);
                for (; i < nums.size(); ++i) {
                    if (nums[i - k] < lv) {
                        lIter = lower.find(nums[i - k]);
                        lower.erase(lIter);
                    } else if (nums[i - k] > lv) {
                        hIter = higher.find(nums[i - k]);
                        higher.erase(hIter);
                    } else {
                        lIter = lower.begin();
                        lv = *lIter;
                        lower.erase(lIter);
                    }
                    if (nums[i] <= lv) {
                        lower.insert(nums[i]);
                    } else if (nums[i] > lv) {
                        higher.insert(nums[i]);
                    }
                    if (lower.size() > higher.size()) {
                        higher.insert(lv);
                        lIter = lower.begin();
                        lv = *lIter;
                        lower.erase(lIter);
                    } else if (lower.size() < higher.size()) {
                        lower.insert(lv);
                        hIter = higher.begin();
                        lv = *hIter;
                        higher.erase(hIter);
                    }
                    ret.push_back(lv);
                }
            } else {
                lIter = lower.begin(); lv = *lIter; lower.erase(lIter);
                hIter = higher.begin(); hv = *hIter; higher.erase(hIter);
                ret.push_back(((long long int)lv + hv) / 2.0);
                for (; i < nums.size(); ++i) {
                    if (nums[i - k] < lv) {
                        lIter = lower.find(nums[i - k]);
                        lower.erase(lIter);
                    } else if (nums[i - k] > hv) {
                        hIter = higher.find(nums[i - k]);
                        higher.erase(hIter);
                    } else if (nums[i - k] == lv) {
                        lIter = lower.begin();
                        lv = *lIter;
                        lower.erase(lIter);
                    } else {
                        hIter = higher.begin();
                        hv = *hIter;
                        higher.erase(hIter);
                    }
        
                    if (nums[i] <= lv) {
                        lower.insert(nums[i]);
                    } else if (nums[i] >= hv) {
                        higher.insert(nums[i]);
                    } else {
                        lower.insert(lv);
                        lv = nums[i];
                    }
                    if (lower.size() > higher.size()) {
                        higher.insert(hv);
                        hv = lv;
                        lIter = lower.begin();
                        lv = *lIter;
                        lower.erase(lIter);
                    } else if (higher.size() > lower.size()) {
                        lower.insert(lv);
                        lv = hv;
                        hIter = higher.begin();
                        hv = *hIter;
                        higher.erase(hIter);
                    }
                    //cout << endl;
                    //cout << "lower" << endl;
                    //for (lIter = lower.begin(); lIter != lower.end(); ++lIter) cout << (*lIter) << endl;
                    //cout << "higher" << endl;
                    //for (hIter = higher.begin(); hIter != higher.end(); ++hIter) cout << (*hIter) << endl;
                    //cout << "lv=" << lv << " hv=" << hv << endl;
                    ret.push_back(((long long int)lv + hv) / 2.0);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    int k;
    Input(k);
    Input(valueVec);

    // solution
    Solution solution;
    vector<double> ret = solution.medianSlidingWindow(valueVec, k);

    // output
    Output(ret);

    return 0;
}
