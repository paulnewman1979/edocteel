#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum3(int k, int n) {
        vector< vector<int> > results;
        if (k > 9) {
            return results;
        }

        int minSum = (1 + k) * k / 2;
        int maxSum = (9 + 10 - k) * k / 2;
        if ((n < minSum) || (n > maxSum)) {
            return results;
        }

        vector<int> tmp(k, 0);
        int tmpSize = 0;
        partialSum(n - minSum, k, tmp, tmpSize, results, 10);

        return results;
    }

    void partialSum(const int sum,
                    const int k,
                    vector<int>& tmp,
                    const int tmpSize,
                    vector< vector<int> >& results,
                    const int preK) {
        if (1 == k) {
            vector<int> result;
            result.push_back(sum + 1);
            int j = 2;
            for (int i=tmpSize-1; i>=0; --i) {
                result.push_back(tmp[i] + j);
                ++j;
            }
            results.push_back(result);
            return;
        }
        int minK = (sum + k - 1) / k;
        int maxK = (sum<9-k)?sum:(9-k);
        if (maxK > preK) {
            maxK = preK;
        }
        for (int i=minK; i<=maxK; i++) {
            cout << "try: " << k << " " << i << endl;
            tmp[tmpSize] = i;
            partialSum(sum - i, k - 1, tmp, tmpSize+1, results, i);
        }
    }
};

int main(int argc, char* argv[])
{
    int n;
    int k;
    cin >> k;
    cin >> n;
    cout << "k = " << k << endl;
    cout << "n = " << n << endl;
    Solution solution;
    vector< vector<int> > result;
    result = solution.combinationSum3(k, n);
    int i;
    int j;
    for (i=0; i<result.size(); ++i) {
        for (j=0; j<result[i].size() - 1; ++j) {
            cout << result[i][j] << " ";
        }
        cout << result[i][j] << endl;
    }

    return 0;
}

