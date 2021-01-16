#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n, 0);
        vector<int> stack;
        int id, time, i, lastTime = 0, pos1, pos2;
        string action;
        for (i = 0; i < logs.size(); ++i) {
            pos1 = logs[i].find(":", 0);
            pos2 = logs[i].find(":", pos1 + 1);
            id = atoi(logs[i].substr(0, pos1).c_str());
            time = atoi(logs[i].substr(pos2 + 1).c_str());
            action = logs[i].substr(pos1 + 1, pos2 - pos1 - 1);
            if (i == 0) {
                stack.push_back(id);
                lastTime = time;
            } else if (action == "start") {
                ret[stack.back()] += time - lastTime;
                stack.push_back(id);
                lastTime = time;
            } else {
                ret[stack.back()] += time - lastTime + 1;
                stack.pop_back();
                lastTime = time + 1;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int n;
    vector<string> valueVec;
    Input(n);
    Input(valueVec);

    // solution
    Solution solution;
    vector<int> ret = solution.exclusiveTime(n, valueVec);

    // output
    Output(ret);

    return 0;
}
