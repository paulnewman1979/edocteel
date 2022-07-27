#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        _nums = nums;
        sort(_nums.begin(), _nums.end(), greater<>());
        if (_nums.size() > _k) {
            _nums.erase(_nums.begin() + k, _nums.end());
        }
        if (_nums.size() == _k) {
            make_heap(_nums.begin(), _nums.end(), greater<>());
            pop_heap(_nums.begin(), _nums.end(), greater<>());
        }
    }
    
    int add(int val) {
        if (_nums.size() == _k - 1) {
            _nums.push_back(val);
            make_heap(_nums.begin(), _nums.end(), greater<>());
            pop_heap(_nums.begin(), _nums.end(), greater<>());
        } else if (_nums.back() < val) {
            _nums.pop_back();
            _nums.push_back(val);
            push_heap(_nums.begin(), _nums.end(), greater<>());
            pop_heap(_nums.begin(), _nums.end(), greater<>());
        }
        return _nums.back();
    }

private:
    int _k;
    vector<int> _nums;
};

int main(int argc, char* argv[])
{
    // input
    int k;
    vector<int> valueVec;
    vector<int> actions;
    Input(k);
    Input(valueVec);
    Input(actions);

    // solution
    KthLargest kl(k, valueVec);

    // output
    for (auto act : actions) {
        cout << kl.add(act) << endl;
    }

    return 0;
}
