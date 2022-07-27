#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > spiralMatrixIII(int R, int C, int r0, int c0) {
        vector< vector<int> > results;
        vector<int> result(2, 0);
        int inBoundCount = 4;
        int r, c;
        int rl = r0;
        int cl = c0;
        int rh = r0 + 1;
        if (rh == R) --inBoundCount;
        int ch = c0 + 1;
        if (ch == C) --inBoundCount;
        result[0] = r0; result[1] = c0; results.push_back(result);
        while (inBoundCount > 0) {
            //cout << "start: " << inBoundCount << " " << rl << " " << rh << " " << cl << " " << ch << endl;

            if (rl >= 0) {
                for (c = max(cl + 1, 0); c <= min(ch, C - 1); ++c) {
                    result[0] = rl; result[1] = c; results.push_back(result);
                    //cout << "HELLO1: " << result[0] << "\t" << result[1] << endl;
                }
            }
            if (--cl == -1) --inBoundCount;

            if (ch < C) {
                for (r = max(rl + 1, 0); r <= min(rh, R - 1); ++r) {
                    result[0] = r; result[1] = ch; results.push_back(result);
                    //cout << "HELLO2: " << result[0] << "\t" << result[1] << endl;
                }
            }
            if (--rl == -1) --inBoundCount;

            if (rh < R) {
                for (c = min(ch - 1, C - 1); c >= max(cl, 0); --c) {
                    result[0] = rh; result[1] = c; results.push_back(result);
                    //cout << "HELLO3: " << result[0] << "\t" << result[1] << endl;
                }
            }
            if (++ch == C) --inBoundCount;

            if (cl >= 0) {
                for (r = min(rh - 1, R - 1); r >= max(rl, 0); --r) {
                    result[0] = r; result[1] = cl; results.push_back(result);
                    //cout << "HELLO4: " << result[0] << "\t" << result[1] << endl;
                }
            }
            if (++rh == R) --inBoundCount;

            //cout << "end: " << inBoundCount << " " << rl << " " << rh << " " << cl << " " << ch << endl;
        }
        return results;
    }
};

int main(int argc, char* argv[])
{
    int R;
    int C;
    int r0;
    int c0;

    cin >> R;
    cin >> C;
    cin >> r0;
    cin >> c0;

    Solution solution;
    vector< vector<int> > result = solution.spiralMatrixIII(R, C, r0, c0);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i][0] << "\t" << result[i][1] << endl;
    }

    return 0;
}
