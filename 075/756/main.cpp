#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int i, j;
        size = bottom.length();
        str.resize(2);
        unordered_map<string, vector<char>> allowedMap;
        for (auto a : allowed) allowedMap[a.substr(0, 2)].push_back(a[2]);
        vector<string> stack(size);
        stack[0] = bottom;
        for (i = 1; i < size; ++i) stack[i].resize(size - i);
        i = 1, j = 0;
        return pyramidTransition(stack, allowedMap, i, j);
    }

private:
    int size;
    string str;

private:
    bool pyramidTransition(vector<string>& stack,
            unordered_map<string, vector<char>>& allowedMap,
            const int i, const int j) {
        str[0] = stack[i - 1][j];
        str[1] = stack[i - 1][j + 1];
        if (allowedMap.find(str) == allowedMap.end()) return false;
        for (auto c: allowedMap[str]) {
            stack[i][j] = c;
            if (i == size - 1) return true;
            else {
                bool ret = (i + j == size - 1) ?
                    pyramidTransition(stack, allowedMap, i + 1, 0) :
                    pyramidTransition(stack, allowedMap, i, j + 1);
                if (ret) return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    // input
    string bottom;
    vector<string> valueVec;
    Input(bottom);
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.pyramidTransition(bottom, valueVec);

    // output
    Output(ret);

    return 0;
}
