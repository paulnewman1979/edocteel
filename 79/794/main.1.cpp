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
        int i, j, size = board.size();
        vector<int> countX(size + size + 2, 0);
        vector<int> countO(size + size + 2, 0);
        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                switch(board[i][j]) {
                case 'X':
                    countX[i]++;
                    countX[size + j]++;
                    break;
                case 'O':
                    countO[i]++;
                    countO[size + j]++;
                default:
                    ;
                }
            }
        }
        for (i = 0; i < size; ++i) {
            switch(board[i][i]) {
            case 'X':
                countX[size + size]++;
                break;
            case 'O':
                countO[size + size]++;
            default:
                ;
            }
            switch(board[i][size - i - 1]) {
            case 'X':
                countX[size + size + 1]++;
                break;
            case 'O':
                countO[size + size + 1]++;
            default:
                ;
            }
        }

        int xWinRow = -1, xWinCol = -1, oWinRow = -1, oWinCol = -1, xNum = 0, oNum = 0;
        int xoWin = 0; // x win -> 1 or y win -> 2 or no win -> 0
        for (i = 0; i < size; ++i) {
            xNum += countX[i];
            if (countX[i] == size) {
                if (xWinRow == -1) xWinRow = i;
                else return false;
            }
            oNum += countO[i];
            if (countO[i] == size) {
                if (oWinRow == -1) oWinRow = i;
                else return false;
            }
            if (countX[size + i] == -1) {
                if (xWinCol == -1) xWinCol = i;
                else return false;
            }
            if (countO[size + i] == -1) {
                if (oWinCol == -1) oWinCol = i;
                else return false;
            }
        }

        if ((xWinRow != -1) || (xWinCol != -1) ||
                (countX[size + size] == size) || (countX[size + size + 1] == size)) {
            xoWin |= 1;
            if (countX[size + size] == size) {
                if (countX[size + size + 1] == size) {
                    if ((size % 2 != 1) || ((xWinRow != -1) && (xWinRow != (size + 1) / 2)) ||
                        ((xWinCol != -1) && (xWinCol != (size + 1) / 2))) {
                        return false;
                    }
                } else if ((xWinRow != -1) && (xWinCol != -1) && (xWinRow != xWinCol)) {
                    return false;
                }
            } else if ((countX[size + size + 1] == size) && (xWinRow != -1) && (xWinCol != -1) && (xWinRow + xWinCol != size - 1)) {
                return false;
            }
        }

        if ((oWinRow != -1) || (oWinCol != -1) ||
                (countX[size + size] == size) || (countX[size + size + 1] == size)) {
            xoWin |= 2;
            if (countX[size + size] == size) {
                if (countX[size + size + 1] == size) {
                    if ((size % 2 != 1) || ((oWinRow != -1) && (oWinRow != (size + 1) / 2)) ||
                        ((oWinCol != -1) && (oWinCol != (size + 1) / 2))) {
                        return false;
                    }
                } else if ((oWinRow != -1) && (oWinCol != -1) && (oWinRow != oWinCol)) {
                    return false;
                }
            } else if ((countX[size + size + 1] == size) && (oWinRow != -1) && (oWinCol != -1) && (oWinRow + oWinCol != size - 1)) {
                return false;
            }
        }

        switch(xoWin) {
        case 0:
            if ((xNum != oNum) && (xNum != oNum + 1)) return false;
            break;
        case 1:
            if (xNum != oNum + 1) return false;
            break;
        case 2:
            if (xNum != oNum) return false;
            break;
        default:
            return false;
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
