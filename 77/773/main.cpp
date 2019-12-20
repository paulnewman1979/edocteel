#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int ret = 0, cur = 0;
        unordered_map<int, int> todo;
        unordered_map<int, int> tmp;
        unordered_set<int> record;
        vector<vector<vector<int>>> actions(6);
        actions[0].push_back(vector<int>{0x0f0000, 1,  4, 0xf0ffff, 1});
        actions[0].push_back(vector<int>{0x000f00, 1, 12, 0xfff0ff, 3});
        actions[1].push_back(vector<int>{0xf00000, 2,  4, 0x0fffff, 0});
        actions[1].push_back(vector<int>{0x00f000, 1,  4, 0xff0fff, 2});
        actions[1].push_back(vector<int>{0x0000f0, 1, 12, 0xffff0f, 4});
        actions[2].push_back(vector<int>{0x0f0000, 2,  4, 0xf0ffff, 1});
        actions[2].push_back(vector<int>{0x00000f, 1, 12, 0xfffff0, 5});
        actions[3].push_back(vector<int>{0x0000f0, 1,  4, 0xffff0f, 4});
        actions[3].push_back(vector<int>{0xf00000, 2, 12, 0x0fffff, 0});
        actions[4].push_back(vector<int>{0x000f00, 2,  4, 0xfff0ff, 3});
        actions[4].push_back(vector<int>{0x00000f, 1,  4, 0xfffff0, 5});
        actions[4].push_back(vector<int>{0x0f0000, 2, 12, 0xf0ffff, 1});
        actions[5].push_back(vector<int>{0x0000f0, 2,  4, 0xffff0f, 4});
        actions[5].push_back(vector<int>{0x00f000, 2, 12, 0xff0fff, 2});

        int curBlank = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) curBlank = i * 3 + j;
                cur |= (board[i][j]<<(20 - i * 12 - j * 4));
            }
        }
        todo[cur] = curBlank;
        do {
            for (auto x : todo) {
                record.insert(x.first);
            }
            if (record.find(0x123450) != record.end()) return ret;

            ++ret;
            tmp.clear();
            for (auto x: todo) {
                cur = x.first;
                curBlank = x.second;
                for (auto action: actions[curBlank]) {
                    int newCur = 0;
                    if (action[1] == 1) {
                        newCur = ((cur & action[0])<<action[2]) | (cur & action[3]);
                    } else {
                        newCur = ((cur & action[0])>>action[2]) | (cur & action[3]);
                    }
                    if (record.find(newCur) == record.end()) {
                        tmp[newCur] = action[4];
                    }
                }
            }
            todo.swap(tmp);
        } while (todo.size() > 0);

        return -1;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.slidingPuzzle(valueGrid);

    // output
    Output(ret);

    return 0;
}
