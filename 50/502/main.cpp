#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool CapitalComp(pair<int, int>& a, pair<int, int>& b) {
    return (a.first < b.first);
}

bool RevenueComp(pair<int, int>& a, pair<int, int>& b) {
    return (a.second < b.second);
}

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        if (Profits.size() == 0) return 0;

        int size = Profits.size(), i, j, ret = W;
        vector<pair<int, int>> leastCapital(size);
        vector<pair<int, int>> maxCapital;
        for (i = 0; i < size; ++i) {
            leastCapital[i].first = Capital[i];
            leastCapital[i].second = Profits[i];
        }
        sort(leastCapital.begin(), leastCapital.end(), CapitalComp);

        if (leastCapital[0].first > W) return 0;
        i = 0; j = 0;
        make_heap(maxCapital.begin(), maxCapital.end(), RevenueComp);
        while (i < k) {
            while ((j < size) && (leastCapital[j].first <= ret)) {
                maxCapital.push_back(leastCapital[j]);
                push_heap(maxCapital.begin(), maxCapital.end(), RevenueComp);
                ++j;
            }
            if (maxCapital.size() == 0) break;
            pop_heap(maxCapital.begin(), maxCapital.end(), RevenueComp);
            if (maxCapital.back().second <= 0) return ret;
            ret += maxCapital.back().second;
            maxCapital.pop_back();
            ++i;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int k, W;
    vector<int> Profits;
    vector<int> Capital;
    Input(k);
    Input(W);
    Input(Profits);
    Input(Capital);

    // solution
    Solution solution;
    int ret = solution.findMaximizedCapital(k, W, Profits, Capital);

    // output
    Output(ret);

    return 0;
}
