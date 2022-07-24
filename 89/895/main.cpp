#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class FreqStack {
public:
    FreqStack() {
        pos = 0;
        make_heap(freqPosNum.begin(), freqPosNum.end(), FreqStack::comp);
    }
    
    void push(int val) {
        valuePoses[val].push_back(pos);
        freqPosNum.push_back(vector<int>({(int)valuePoses[val].size(), pos, val}));
        push_heap(freqPosNum.begin(), freqPosNum.end(), comp);
        ++pos;
    }
    
    int pop() {
        pop_heap(freqPosNum.begin(), freqPosNum.end(), comp);
        int val = freqPosNum.back()[2];
        freqPosNum.pop_back();
        valuePoses[val].pop_back();
        return val;
    }

private:
    static bool comp(vector<int>& a, vector<int>& b) {
        return ((a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1])));
    }

private:
    int pos;
    unordered_map<int, vector<int>> valuePoses;
    vector<vector<int>> freqPosNum;
};

int main(int argc, char* argv[])
{
    vector<vector<int>> values;
    Input(values);

    FreqStack fc;
    for (auto& value: values) {
        if (value[0] == 1) {
            fc.push(value[1]);
        } else {
            cout << fc.pop() << endl;
        }
    }

    return 0;
}
