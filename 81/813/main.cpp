#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        double ret = 0.0, sum;
        int i, j, k;
        vector<vector<double>> sumAverage(A.size(), vector<double>(A.size(), 0.0));
        for (i = 0; i < A.size(); ++i) {
            sum = 0.0;
            for (j = i; j < A.size(); ++j) {
                sum += A[j];
                sumAverage[i][j] = sum / (j - i + 1);
                //cout << "sumAverage[" << i << "][" << j << "]=" << sumAverage[i][j] << endl;
            }
        }
        if (1 == K) { return sumAverage[0][A.size() - 1]; }

        vector<vector<double>> maxSumAverage(K, vector<double>(A.size(), 0.0));
        sum = 0.0;
        for (i = 0; i < A.size(); ++i) {
            sum += A[i];
            maxSumAverage[1][i] = sumAverage[0][i];
            //cout << "maxSumAverage[1][" << i << "]=" << maxSumAverage[1][i] << endl;
        }
        for (k = 2; k < K; ++k) {
            for (i = k - 1; i < A.size(); ++i) {
                for (j = k - 1; j <= i; ++j) {
                    if (maxSumAverage[k - 1][j - 1] + sumAverage[j][i] > maxSumAverage[k][i]) {
                        maxSumAverage[k][i] = maxSumAverage[k - 1][j - 1] + sumAverage[j][i];
                    }
                }
                //cout << "maxSumAverage[" << k << "][" << i << "]=" << maxSumAverage[k][i] << endl;
            }
        }
        ret = 0.0;
        for (j = K - 1; j < A.size(); ++j) {
            sum = maxSumAverage[K - 1][j - 1] + sumAverage[j][A.size() - 1];
            if (sum > ret) ret = sum;
        }
        return ret;
    }
};

template <typename baseType>
void loadVector(vector<baseType>& valueVec) {
    int n;
    baseType value;
    cin >> n;
    while (n-- > 0) {
        cin >> value;
        valueVec.push_back(value);
    }
}

template <>
void loadVector(vector<string>& valueVec) {
    int n;
    string value;
    cin >> n;
    while (n-- > 0) {
        getline(cin, value);
        valueVec.push_back(value);
    }
}

int main(int argc, char* argv[])
{
    // input
    int K;
    vector<int> valueVec;
    Input(K);
    Input(valueVec);

    // solution
    Solution solution;
    double ret = solution.largestSumOfAverages(valueVec, K);

    // output
    cout << ret << endl;

    return 0;
}
