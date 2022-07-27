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
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        if (size <= 2) return 0;
        int ret = 0, i, j, gap;
        vector<unordered_map<int, pair<int, int>>> numGap(size);
        unordered_map<int, int> numCount;
        unordered_map<int, pair<int, int>>::iterator iter, iter1;
        vector<pair<int, int>> newA;

        if (A[0] == A[1]) {
            numGap[1][0] = pair(2, 0);
        } else if (A[0] <= 0) {
            if (A[1] <= INT_MAX + A[0]) {
                numGap[1][A[1] - A[0]] = pair(0, 1);
            }
        } else if (A[0] > 0) {
            if (A[1] >= INT_MIN + A[0]) {
                numGap[1][A[1] - A[0]] = pair(0, 1);
            }
        }
        for (i = 2; i < size; ++i) {
            //cout << "A[" << i << "]=" << A[i] << endl;
            for (j = i - 1; j >= 0; --j) {
                if ((A[j] < 0) && (A[i] > INT_MAX + A[j])) continue;
                if ((A[j] > 0) && (A[i] < INT_MIN + A[j])) continue;
                gap = A[i] - A[j];
                iter = numGap[j].find(gap);
                iter1 = numGap[i].find(gap);
                if (gap == 0) {
                    if (iter1 == numGap[i].end()) {
                        if (iter == numGap[j].end()) {
                            numGap[i][0].first = 2;
                            numGap[i][0].second = 0;
                            //cout << "new gap=" << gap << " (" << numGap[i][0].first
                            //    << ", " << numGap[i][0].second << ")" << endl;
                        } else {
                            ret += getRet(iter->second.first);
                            //cout << "gap=" << gap << " ret=" << ret << endl;
                            numGap[i][0].first = iter->second.first + 1;
                            numGap[i][0].second = 0;
                            //cout << "new gap=" << gap << " (" << numGap[i][0].first
                            //    << ", " << numGap[i][0].second << ")" << endl;
                        }
                    } 
                } else {
                    if (iter != numGap[j].end()) {
                        ret += iter->second.first + iter->second.second;
                        //cout << "gap=" << gap << " ret=" << ret << endl;
                        if (iter1 == numGap[i].end()) {
                            numGap[i][gap].first = iter->second.first + iter->second.second;
                            numGap[i][gap].second = 1;
                            //cout << "new gap=" << gap << " (" << numGap[i][gap].first
                            //    << ", " << numGap[i][gap].second << ")" << endl;
                        } else {
                            iter1->second.first += iter->second.first + iter->second.second;
                            iter1->second.second++;
                            //cout << "add gap=" << gap << " (" << numGap[i][gap].first
                            //    << ", " << numGap[i][gap].second << ")" << endl;
                        }
                    } else {
                        //cout << "gap=" << gap << " ret=" << ret << endl;
                        if (iter1 == numGap[i].end()) {
                            numGap[i][gap].first = 0;
                            numGap[i][gap].second = 1;
                            //cout << "new gap=" << gap << " (" << numGap[i][gap].first
                            //    << ", " << numGap[i][gap].second << ")" << endl;
                        } else {
                            iter1->second.second++;
                            //cout << "add gap=" << gap << " (" << numGap[i][gap].first
                            //    << ", " << numGap[i][gap].second << ")" << endl;
                        }
                    }
                }
            }
        }
        return ret;
    }

private:
    int getRet(int n) {
        if (n == 1) return 0;
        else if (n == 2) return 1;
        else {
            while (dp.size() <= n) dp.push_back(0);
            if (dp[n] == 0) {
                long long int k = 1;
                for (int i = 0; i < n; ++i) {
                    k = k * 2;
                }
                k -= n + 1;
                dp[n] = k;
            }
        }
        return dp[n];
    }

private:
    vector<int> dp;
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.numberOfArithmeticSlices(valueVec);

    // output
    Output(ret);

    return 0;
}
