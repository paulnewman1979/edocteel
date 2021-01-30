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
    int findRotateSteps(string ring, string key) {
        if (key.length() == 0) return 0; 
        unordered_map<char, vector<int>> charPos(26);
        vector<vector<pair<int, int>>> leastStep(2);
        int i, size = ring.length(), index = 0, prevIndex, minStep, curStep;
        for (i = 0; i < size; ++i) {
            charPos[ring[i]].push_back(i);
        }
        index = 0;
        leastStep[0].push_back(make_pair(0, 0));
        for (i = 0; i < key.length(); ++i) {
            prevIndex = index;
            index = 1 - prevIndex;
            leastStep[index].clear();
            for (auto& pos : charPos[key[i]]) {
                minStep = INT_MAX;
                for (auto& p : leastStep[prevIndex]) {
                    if (p.first < pos) {
                        curStep = p.second + min(pos - p.first, p.first+ size - pos);
                    } else {
                        curStep = p.second + min(p.first - pos, pos + size - p.first);
                    }
                    if (curStep < minStep) minStep = curStep;
                }
                leastStep[index].push_back(make_pair(pos, minStep));
            }
        }
        minStep = INT_MAX;
        for (auto& ls : leastStep[index]) {
            if (ls.second < minStep) minStep = ls.second;
        }
        return minStep + key.length();
	}
};

int main(int argc, char* argv[])
{
    // input
    string ring, key;
    Input(ring);
    Input(key);

    // solution
    Solution solution;
	int ret = solution.findRotateSteps(ring, key);

    // output
    Output(ret);

    return 0;
}
