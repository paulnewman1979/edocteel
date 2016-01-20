#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validateMask(char ch, int& mask) {
        int localMask = 0;
        if ((ch >= '0') && (ch <= '9')) {
            localMask = 1<<(ch - '0');
            if ( (localMask & mask) != 0) {
                return false;
            } else {
                mask |= localMask;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int mask = 0x1FF;
        int i, j, k, l;
        for (i=0; i<9; ++i) {
            mask = 0;
            for (j=0; j<9; ++j) {
                if (!validateMask(board[i][j], mask)) {
                    return false;
                }
            }
        }
        for (j=0; j<9; ++j) {
            mask = 0;
            for (i=0; i<9; ++i) {
                if (!validateMask(board[i][j], mask)) {
                    return false;
                }
            }
        }
        for (i=0; i<9; i+=3) {
            for (j=0; j<9; j+=3) {
                mask = 0;
                for (k=0; k<3; ++k) {
                    for (l=0; l<3; ++l) {
                        if (!validateMask(board[i+k][j+l]), mask) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
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
}
