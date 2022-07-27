#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int i, j, xCount = 0, oCount = 0;
        int xoWin = 0;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') ++xCount;
                else if (board[i][j] == 'O') ++oCount;
            }
            if ((board[i][0] != ' ') && (board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) {
                xoWin |= ((board[i][0] == 'X') ? 1 : 2);
            }
            if ((board[0][i] != ' ') && (board[0][i] == board[1][i]) && (board[0][i] == board[2][i])) {
                xoWin |= ((board[0][i] == 'X') ? 1 : 2);
            }
        }
        if ((board[0][0] != ' ') && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) {
            xoWin |= ((board[0][0] == 'X') ? 1 : 2);
        }
        if ((board[2][0] != ' ') && (board[2][0] == board[1][1]) && (board[2][0] == board[0][2])) {
            xoWin |= ((board[2][0] == 'X') ? 1 : 2);
        }
        switch(xoWin) {
        case 3:
            return false;
            break;
        case 1:
            if (xCount != oCount + 1) return false;
            break;
        case 2:
            if (xCount != oCount) return false;
            break;
        default:
            if ((xCount != oCount) && (xCount != oCount + 1)) return false;
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.validTicTacToe(valueVec);

    // output
    Output(ret);

    return 0;
}
