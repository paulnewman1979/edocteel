#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i, j;
        mark.resize(board.size());
        for (i = 0; i < board.size(); ++i) {
            mark[i].resize(board[i].size(), true);
        }

        for (i = 0; i < board.size(); ++i) {
            for (j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    mark[i][j] = false;
                    if (exist(board, word, i, j, 1)) {
                        return true;
                    }
                    mark[i][j] = true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board,
            string& word,
            const int i,
            const int j,
            const int idx) {
        if (idx == word.size()) {
            return true;
        }

        if ((i > 0) && (j < board[i-1].size()) && mark[i-1][j] &&
                (board[i-1][j] == word[idx])) {
            mark[i-1][j] = false;
            if (exist(board, word, i - 1, j, idx + 1)) {
                return true;
            }
            mark[i-1][j] = true;
        }

        if ((j > 0) && mark[i][j-1] &&
            (board[i][j-1] == word[idx])) {
            mark[i][j-1] = false;
            if (exist(board, word, i, j - 1, idx + 1)) {
                return true;
            }
            mark[i][j-1] = true;
        }

        if ((i + 1 < board.size()) && (j < board[i+1].size()) && mark[i+1][j] &&
                (board[i+1][j] == word[idx])) {
            mark[i+1][j] = false;
            if (exist(board, word, i + 1, j, idx + 1)) {
                return true;
            }
            mark[i+1][j] = true;
        }
        if ((j + 1 < board[i].size()) && mark[i][j+1] &&
                (board[i][j+1] == word[idx])) {
            mark[i][j+1] = false;
            if (exist(board, word, i, j + 1, idx + 1)) {
                return true;
            }
            mark[i][j+1] = true;
        }
        return false;
    }
private:
    vector<vector<bool>> mark;
};

int main(int argc, char* argv[])
{
    string word;
	vector< vector<char> > board;
	vector<char> row;

	int rowNum;
    int rowLen;
    cin >> word;
	cin >> rowNum;
    char value;
	while (rowNum > 0) {
        cin >> rowLen;
        row.clear();
        while (rowLen > 0) {
            cin >> value;
            row.push_back(value);
            --rowLen;
        }
	    board.push_back(row);
        --rowNum;
	}

    Solution solution;
	cout << (solution.exist(board, word)?"true":"false") << endl;

    return 0;
}
