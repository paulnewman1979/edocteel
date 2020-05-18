#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> flowfree(int N, vector<vector<int>>& A) {
        this->N = N;
        flowboard.resize(N);
        for (auto& i : flowboard) i.resize(N, 0);
        colorSize = A.size();
        for (int i = 0; i < A.size(); ++i) {
            flowboard[A[i][0]][A[i][1]] = i + 1;
            flowboard[A[i][2]][A[i][3]] = i + 11;
        }

        int colorIndex = 0;
        vector<pair<int, int>> steps(N * N);
        int stepIndex = 0;
        int sameColor = 1;
        steps[stepIndex].first = A[0][0];
        steps[stepIndex].second = A[0][1];
        ++stepIndex;

        nextColorIndex = 1;
        flow(colorIndex, steps, stepIndex, A, sameColor);

        return flowboard;
    }

private:
    int nextColorIndex;
    int colorSize;
    int N;
    vector<vector<int>> flowboard;

private:
    bool flow(const int colorIndex,
            vector<pair<int, int>>& steps,
            const int stepIndex,
            const vector<vector<int>>& A,
            const int sameColor) {
        if (sameColor >= N * 4) return false;

        if (colorIndex == nextColorIndex) {
            cout << "new color " << colorIndex << endl;
            ++nextColorIndex;
        }

        int posX = steps[stepIndex-1].first;
        int posY = steps[stepIndex-1].second;

        //cout << "try color " << colorIndex << ", stepIndex=" << stepIndex << ", pos (" << posX << ", " << posY << ")" << endl;
        if (posX > 0) {
            if (flowboard[posX-1][posY] == colorIndex + 11) {
                int newColorIndex = colorIndex + 1;
                if (newColorIndex == colorSize) return true;
                else {
                    steps[stepIndex].first = posX - 1;
                    steps[stepIndex].second = posY;
                    steps[stepIndex+1].first = A[newColorIndex][0];
                    steps[stepIndex+1].second = A[newColorIndex][1];
                    if (flow(newColorIndex, steps, stepIndex + 2, A, 1)) return true;
                }
            } else if (flowboard[posX-1][posY] == 0) {
                flowboard[posX-1][posY] = colorIndex + 1;
                steps[stepIndex].first = posX - 1;
                steps[stepIndex].second = posY;
                if(flow(colorIndex, steps, stepIndex + 1, A, sameColor + 1)) return true;
                flowboard[posX-1][posY] = 0;
            }
        }

        if (posY > 0) {
            if (flowboard[posX][posY-1] == colorIndex + 11) {
                int newColorIndex = colorIndex + 1;
                if (newColorIndex == colorSize) return true;
                else {
                    steps[stepIndex].first = posX;
                    steps[stepIndex].second = posY - 1;
                    steps[stepIndex+1].first = A[newColorIndex][0];
                    steps[stepIndex+1].second = A[newColorIndex][1];
                    if (flow(newColorIndex, steps, stepIndex + 2, A, 1)) return true;
                }
            } else if (flowboard[posX][posY-1] == 0) {
                flowboard[posX][posY-1] = colorIndex + 1;
                steps[stepIndex].first = posX;
                steps[stepIndex].second = posY - 1;
                if(flow(colorIndex, steps, stepIndex + 1, A, sameColor + 1)) return true;
                flowboard[posX][posY - 1] = 0;
            }
        }

        if (posX < N - 1) {
            if (flowboard[posX+1][posY] == colorIndex + 11) {
                int newColorIndex = colorIndex + 1;
                if (newColorIndex == colorSize) return true;
                else {
                    steps[stepIndex].first = posX + 1;
                    steps[stepIndex].second = posY;
                    steps[stepIndex+1].first = A[newColorIndex][0];
                    steps[stepIndex+1].second = A[newColorIndex][1];
                    if (flow(newColorIndex, steps, stepIndex + 2, A, 1)) return true;
                }
            } else if (flowboard[posX+1][posY] == 0) {
                flowboard[posX+1][posY] = colorIndex + 1;
                steps[stepIndex].first = posX + 1;
                steps[stepIndex].second = posY;
                if(flow(colorIndex, steps, stepIndex + 1, A, sameColor + 1)) return true;
                flowboard[posX+1][posY] = 0;
            }
        }

        if (posY < N - 1) {
            if (flowboard[posX][posY+1] == colorIndex + 11) {
                int newColorIndex = colorIndex + 1;
                if (newColorIndex == colorSize) return true;
                else {
                    steps[stepIndex].first = posX;
                    steps[stepIndex].second = posY + 1;
                    steps[stepIndex+1].first = A[newColorIndex][0];
                    steps[stepIndex+1].second = A[newColorIndex][1];
                    if (flow(newColorIndex, steps, stepIndex + 2, A, 1)) return true;
                }
            } else if (flowboard[posX][posY+1] == 0) {
                flowboard[posX][posY+1] = colorIndex + 1;
                steps[stepIndex].first = posX;
                steps[stepIndex].second = posY + 1;
                if(flow(colorIndex, steps, stepIndex + 1, A, sameColor + 1)) return true;
                flowboard[posX][posY + 1] = 0;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    // input
    int N;
	vector<vector<int>> edges;
    Input(N);
    Input(edges);

    // solution
    Solution solution;
	vector<vector<int> > results = solution.flowfree(N, edges);

    // output
    Output(results);

    return 0;
}
