#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void solve(vector< vector<char> >& board) {
        int height = board.size();
        int width = (height>0)?board[0].size():0;
		if ( (height <= 2) || (width <= 2) ) {
			return;
		}

		vector< pair<int, int> > pos;
		int x;
		int y;
		for (y=0; y<width; ++y) {
			if (board[0][y] == 'O') {
				board[0][y] = 'Y';
				pos.push_back(pair<int, int>(0, y));
			}
			if (board[height-1][y] == 'O') {
				board[height-1][y] = 'Y';
				pos.push_back(pair<int, int>(height-1, y));
			}
		}
		for (x=1; x<height-1; ++x) {
			if (board[x][0] == 'O') {
				board[x][0] = 'Y';
				pos.push_back(pair<int, int>(x, 0));
			}
			if (board[x][width-1] == 'O') {
				board[x][width-1] = 'Y';
				pos.push_back(pair<int, int>(x, width-1));
			}
		}

		while (pos.size() > 0) {
			pair<int, int> curPos = pos.back();
			pos.pop_back();

			x = curPos.first;
			y = curPos.second;
			if ((x - 1 > 0) &&
				(board[x-1][y] == 'O')) {
				board[x-1][y] = 'Y';
				pos.push_back(pair<int, int>(x-1, y));
			}
			if ( (x + 1 < height) &&
				(board[x+1][y] == 'O') ) {
				board[x+1][y] = 'Y';
				pos.push_back(pair<int, int>(x+1, y));
			}
			if ((y - 1 > 0) &&
				(board[x][y-1] == 'O')) {
				board[x][y-1] = 'Y';
				pos.push_back(pair<int, int>(x, y-1));
			}
			if ((y + 1 < width) &&
				(board[x][y+1] == 'O')) {
				board[x][y+1] = 'Y';
				pos.push_back(pair<int, int>(x, y+1));
			}
		}

		for (x=0; x<height; ++x) {
			for (y=0; y<width; ++y) {
				if (board[x][y] == 'O') {
					board[x][y] = 'X';
				} else if (board[x][y] == 'Y') {
					board[x][y] = 'O';
				}
			}
		}
    }
};

int main(int argc, char* argv[])
{
	vector< vector<char> > board;
	vector<char> row;
	char n;

	cin >> n;
	while (n != '.') {
		if (n == ',') {
			board.push_back(row);
			row.clear();
		} else {
			row.push_back(n);
		}

		cin >> n;
	}

    Solution solution;
	solution.solve(board);

	int i, j;
	for (i=0; i<board.size(); ++i) {
		for (j=0; j<board[i].size(); ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}

    return 0;
}
