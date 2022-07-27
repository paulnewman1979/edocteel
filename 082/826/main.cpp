#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

const int MAX_DIFFICULT = 100000;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int totalProfit = 0, maxProfit = 0, i;
        vector<int> maxProfitVec(MAX_DIFFICULT + 1, 0);
        for (i = 0; i < difficulty.size(); ++i) {
            if (profit[i] > maxProfitVec[difficulty[i]]) {
                maxProfitVec[difficulty[i]] = profit[i];
            }
        }
        for (i = 1; i <= MAX_DIFFICULT; ++i) {
            if (maxProfit > maxProfitVec[i]) {
                maxProfitVec[i] = maxProfit;
            } else {
                maxProfit = maxProfitVec[i];
            }
        }
        for (i = 0; i < worker.size(); ++i) {
            totalProfit += maxProfitVec[worker[i]];
        }
        return totalProfit;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> difficulty;
    vector<int> profit;
    vector<int> worker;
    Input(difficulty);
    Input(profit);
    Input(worker);

    // solution        
    Solution solution;
    int ret = solution.maxProfitAssignment(difficulty, profit, worker);

    // output
    cout << ret << endl;

    return 0;
}
