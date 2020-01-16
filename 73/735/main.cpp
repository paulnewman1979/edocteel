#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <functional>
#include <algorithm>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> pos;
        vector<int> neg;
        for (auto p : asteroids) {
            if (p > 0) pos.push_back(p);
            else {
                while ((pos.size() > 0) && (pos.back() < -p)) {
                    pos.pop_back();
                }
                if (pos.size() == 0) {
                    neg.push_back(p);
                } else if (pos.back() == -p) {
                    pos.pop_back();
                }
            }
        }

        vector<int> ret(pos.size() + neg.size());
        merge(neg.begin(), neg.end(), pos.begin(), pos.end(), ret.begin());

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> words;
    Input(words);

    // solution
    Solution solution;
    vector<int> ret = solution.asteroidCollision(words);

    // output
    Output(ret);

    return 0;
}
