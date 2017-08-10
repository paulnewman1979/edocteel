#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool solveSudoku(vector< vector<char> >& board,
                    int* hmask, int* vmask, int* bmask, const int i, const int j) {
        if ((9 == i) && (0 == j)) {
            return true;
        }

        bool found = false;
        int nexti, nextj;
        int k = (i/3)*3 + (j/3);
        int l;
        if (8 == j) {
            nextj = 0;
            nexti = i + 1;
        } else {
            nexti = i;
            nextj = j + 1;
        }

        if (board[i][j] == '.') {
            int allmask = hmask[i] | vmask[j] | bmask[k];
            l = 0;
            while (l <= 8) {
                int tmpMask = 1<<l;
                if ( ( tmpMask & allmask) == 0) {
                    board[i][j] = '1' + l;
                    hmask[i] |= tmpMask;
                    vmask[j] |= tmpMask;
                    bmask[k] |= tmpMask;
                    //printf("DEBUG: (%d,%d,%d) test %c", i, j, k, board[i][j]);
                    //printf("DEBUG: new mask (%x, %x, %x)\n", hmask[i], vmask[j], bmask[k]);
                    found = solveSudoku(board, hmask, vmask, bmask, nexti, nextj);
                    if (found) {
                        return true;
                    } else {
                        hmask[i] ^= tmpMask;
                        vmask[j] ^= tmpMask;
                        bmask[k] ^= tmpMask;
                    }
                    //printf("DEBUG: recover mask (%d, %d, %d) (%x, %x, %x)\n", i, j, k, hmask[i], vmask[j], bmask[k]);
                }
                ++ l;
            }
            board[i][j] = '.';
        } else {
            //printf("DEBUG: (%d,%d,%d) fixed %c\n", i, j, k, board[i][j]);
            //printf("DEBUG: fixed mask (%x, %x, %x)\n", hmask[i], vmask[j], bmask[k]);
            found = solveSudoku(board, hmask, vmask, bmask, nexti, nextj);
        }

        return found;
    }

    void solveSudoku(vector< vector<char> >& board) {
        int hmask[9];
        int vmask[9];
        int bmask[9];
        int i, j, k;
        int mask;
        for (i=0; i<9; ++i) {
            hmask[i] = 0;
            vmask[i] = 0;
            bmask[i] = 0;
        }
        for (i=0; i<9; ++i) {
            for (j=0; j<9; ++j) {
                if (board[i][j] != '.') {
                    mask = 1 << (board[i][j] - '1');
                    hmask[i] |= mask;
                    vmask[j] |= mask;
                    k = (i/3)*3 + (j/3);
                    bmask[k] |= mask;
                }
            }
        }

        solveSudoku(board, hmask, vmask, bmask, 0, 0);
    }
};

int main(int argc, char* argv[])
{
    vector< vector<char> > board;
    char ch;
    cin >> ch;
    vector<char> array;
    while (ch != '!') {
        if (ch == ',') {
            board.push_back(array);
            array.clear();
        } else {
            array.push_back(ch);
        }
        cin >> ch;
    }

    Solution solution;
    solution.solveSudoku(board);
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
