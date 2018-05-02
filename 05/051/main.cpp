#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector< vector<string> > solveNQueens(int n)
	{
        n_ = n;
		columnMask_.resize(n, 1);
        pivot1Mask_.resize(n * 2 - 1, 1);
        pivot2Mask_.resize(n * 2 - 1, 1);
        pos_.resize(n, 0);

        constructString();

        solveNQueens_(0);
        
        return results_;
    }

    void constructString() {
        std::string str(n_, '.');
        int i;
        for (i = 0; i < n_; ++i) {
            printStr_.push_back(str);
            printStr_.back()[i] = 'Q';
        }
    }

    void solveNQueens_(const int y) {
        for (int x = 0; x < n_; ++x) {
            if (columnMask_[x] & pivot1Mask_[x + y] & pivot2Mask_[n_ - 1 - x + y]) {
                if (y == n_ - 1) {
                    pos_[y] = x;
                    vector<std::string> result;
                    for (int i = 0; i < pos_.size(); ++i) {
                        result.push_back(printStr_[pos_[i]]);
                    }
                    results_.push_back(result);
                } else {
                    columnMask_[x] = 0;
                    pivot1Mask_[x + y] = 0;
                    pivot2Mask_[n_ - 1 - x + y] = 0;
                    pos_[y] = x;

                    solveNQueens_(y + 1);

                    columnMask_[x] = 1;
                    pivot1Mask_[x + y] = 1;
                    pivot2Mask_[n_ - 1 - x + y] = 1;
                }
            }
        }
    }

private:
    int n_;
    vector<int> columnMask_;
    vector<int> pivot1Mask_;
    vector<int> pivot2Mask_;
    vector<int> pos_;
    vector<std::string> printStr_;
    vector< vector<string> > results_;
};

int main(int argc, char* argv[])
{
	int n;
	cin >> n;

    Solution solution;
	vector< vector<string> > results = solution.solveNQueens(n);

    return 0;
}
