#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1], xSize, ySize, nCount;
        vector<vector<int>> neighbors({{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}});
        vector<pair<int, int>> todo;
        switch(board[x][y]) {
          case 'M':
              board[x][y] = 'X';
            break;
          case 'E':
            xSize = board.size();
            ySize = board[0].size();
            todo.push_back(pair(x, y));
            while (todo.size() > 0) {
                x = todo.back().first;
                y = todo.back().second;
                todo.pop_back();
                nCount = 0;
                for (const auto& n : neighbors) {
                    if ((x + n[0] >= 0) && (x + n[0] < xSize) &&
                        (y + n[1] >= 0) && (y + n[1] < ySize)) {
                        if (board[x + n[0]][y + n[1]] == 'M') {
                            ++nCount;
                        }
                    }
                }
                if (nCount == 0) {
                    board[x][y] = 'B';
                    for (const auto& n : neighbors) {
                        if ((x + n[0] >= 0) && (x + n[0] < xSize) &&
                            (y + n[1] >= 0) && (y + n[1] < ySize) &&
                            (board[x + n[0]][y + n[1]] == 'E')) {
                            todo.push_back(pair(x + n[0], y + n[1]));
                        }
                    }
                } else {
                    board[x][y] = '0' + nCount;
                }
            }
            break;
          default:
            ;
        }
        return board;
    }
};

int main(int argc, char* argv[])
{
    // input
	vector<vector<char>> valueGrid;
    vector<int> click;
    Input(click);
    Input(valueGrid);

    // solution
    Solution solution;
	vector<vector<char>> ret = solution.updateBoard(valueGrid, click);

    // output
    Output(ret);

    return 0;
}
