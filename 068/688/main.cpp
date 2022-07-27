#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0) return 1.0;
        if (N < 3) return 0.0;
        int i, j;
        vector< vector< vector<double> > > probabilities(2, vector< vector<double> >(N, vector<double>(N, 0)));
        
        // initializing
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                if (i > 1) {
                    if (j > 0) probabilities[0][i][j] += 0.125;
                    if (j < N - 1) probabilities[0][i][j] += 0.125;
                }
                if (i > 0) {
                    if (j > 1) probabilities[0][i][j] += 0.125;
                    if (j < N - 2) probabilities[0][i][j] += 0.125;
                }
                if (i < N - 2) {
                    if (j > 0) probabilities[0][i][j] += 0.125;
                    if (j < N - 1) probabilities[0][i][j] += 0.125;
                }
                if (i < N - 1) {
                    if (j > 1) probabilities[0][i][j] += 0.125;
                    if (j < N - 2) probabilities[0][i][j] += 0.125;
                }
            }
        }

        // calculate
        int k = 1;
        while (k < K) {
            int curIndex = k % 2;
            int preIndex = 1 - curIndex;
            for (i = 0; i < N; ++i) {
                for (j = 0; j < N; ++j) {
                    probabilities[curIndex][i][j] = 0.0;
                    if (i > 1) {
                        if (j > 0) probabilities[curIndex][i][j] += probabilities[preIndex][i - 2][j - 1] / 8;
                        if (j < N - 1) probabilities[curIndex][i][j] += probabilities[preIndex][i - 2][j + 1] / 8;
                    }
                    if (i > 0) {
                        if (j > 1) probabilities[curIndex][i][j] += probabilities[preIndex][i - 1][j - 2] / 8;
                        if (j < N - 2) probabilities[curIndex][i][j] += probabilities[preIndex][i - 1][j + 2] / 8;
                    }
                    if (i < N - 2) {
                        if (j > 0) probabilities[curIndex][i][j] += probabilities[preIndex][i + 2][j - 1] / 8;
                        if (j < N - 1) probabilities[curIndex][i][j] += probabilities[preIndex][i + 2][j + 1] / 8;
                    }
                    if (i < N - 1) {
                        if (j > 1) probabilities[curIndex][i][j] += probabilities[preIndex][i + 1][j - 2] / 8;
                        if (j < N - 2) probabilities[curIndex][i][j] += probabilities[preIndex][i + 1][j + 2] / 8;
                    }
                }
            }
            ++k;
        }

        k = (k + 1) % 2;
        return probabilities[k][r][c];
    }
};

int main(int argc, char* argv[])
{
    int N;
    int K;
    int r;
    int c;

    cin >> N;
    cin >> K;
    cin >> r;
    cin >> c;

    Solution solution;
	cout << solution.knightProbability(N, K, r, c) << endl;

    return 0;
}
