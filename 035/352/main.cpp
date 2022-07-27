#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool vc(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        int pos;
        vector<int> newVal({val, val});
        vector<vector<int>>::iterator iter = lower_bound(r.begin(), r.end(), newVal, vc);
        if (iter != r.end()) {
            pos = iter - r.begin();
            if (val == r[pos][0]) {
            } else if (val + 1 == r[pos][0]) {
                if ((pos > 0) && (r[pos - 1][1] == val - 1)) {
                    r[pos - 1][1] = r[pos][1];
                    r.erase(iter);
                } else {
                    r[pos][0] = val;
                }
            } else if (pos > 0) {
                if (r[pos - 1][1] == val - 1) {
                    r[pos - 1][1] = val;
                } else if (r[pos - 1][1] < val ) {
                    r.insert(r.begin() + pos, vector(2, val));
                }
            } else {
                r.insert(r.begin(), newVal);
            }
        } else if (r.size() > 0) {
            pos = r.size() - 1;
            if (r[pos][1] == val - 1) {
                r[pos][1] = val;
            } else if (r[pos][1] < val) {
                r.push_back(vector(2, val));
            }
        } else {
            r.push_back(vector(2, val));
        }
    }
    
    vector<vector<int>> getIntervals() {
        return r;
    }

private:
    vector<vector<int>> r;
};

int main(int argc, char* argv[])
{
    // input
    vector<int> nums;
    Input(nums);

    // solution
    SummaryRanges sr;
    vector<vector<int>> ret;
    for (int num : nums) {
        if (num >= 0) {
            sr.addNum(num);
        } else {
            ret = sr.getIntervals();
            Output(ret);
            cout << endl;
        }
    }

    return 0;
}
