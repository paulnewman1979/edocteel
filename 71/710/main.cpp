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
    Solution(int N, vector<int>& blacklist) {
        int i;
        _size = N - blacklist.size();
        unordered_set<int> ignore;
        for (i = 0; i < blacklist.size(); ++i) {
            if (blacklist[i] >= _size) {
                ignore.insert(blacklist[i]);
            }
        }
        i = N;
        while (ignore.find(i) != ignore.end()) --i;
        sort(blacklist.begin(), blacklist.end());
        for (auto b : blacklist) {
            --i;
            while (ignore.find(i) != ignore.end()) --i;
            _map[b] = i;
        }
    }
                
    int pick() {
        int n = rand() % _size;
        if (_map.find(n) != _map.end()) {
            return _map[n];
        } else {
            return n;
        }
    }

private:
    int _size;
    unordered_map<int, int> _map;
};

int main(int argc, char* argv[])
{
    // input
    int N;
    int K;
    vector<int> valueVec;
    Input(N);
    Input(K);
    Input(valueVec);

    // solution
    vector<int> ret;
    Solution solution(N, valueVec);
    for (int i = 0; i < K; ++i) {
        ret.push_back(solution.pick());
    }

    // output
    Output(ret);

    return 0;
}
