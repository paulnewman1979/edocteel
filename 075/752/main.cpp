#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ret = 0, i;
        char ch;
        unordered_set<string> mark;

        for (auto p : deadends) mark.insert(p);

        if (mark.find("0000") != mark.end() ||
                mark.find(target) != mark.end())
            return -1;

        vector<string> todo;
        mark.insert("0000");
        todo.push_back("0000");
        while (todo.size() > 0) {
            ++ret;
            vector<string> newTodo;
            for (auto p : todo) {
                for (i = 0; i < 4; ++i) {
                    ch = p[i];

                    p[i] = (p[i] == '9') ? p[i] = '0' : (p[i] + 1);
                    if (mark.find(p) == mark.end()) { mark.insert(p); newTodo.push_back(p); }
                    p[i] = ch;

                    p[i] = (p[i] == '0') ? p[i] = '9' : (p[i] - 1);
                    if (mark.find(p) == mark.end()) { mark.insert(p); newTodo.push_back(p); }

                    p[i] = ch;
                }
            }

            if (mark.find(target) == mark.end()) {
                todo.swap(newTodo);
            } else {
                return ret;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    // input
    string target;
    vector<string> valueVec;
    Input(target);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.openLock(valueVec, target);

    // output
    Output(ret);

    return 0;
}
