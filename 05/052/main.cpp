#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int totalNQueens(int n)
	{
        resultCount_ = 0;
        n_ = n;
		columnMask_.resize(n, 1);
        pivot1Mask_.resize(n * 2 - 1, 1);
        pivot2Mask_.resize(n * 2 - 1, 1);
        pos_.resize(n, 0);

        solveNQueens_(0);
        
        return resultCount_;
    }

    void solveNQueens_(const int y) {
        for (int x = 0; x < n_; ++x) {
            if (columnMask_[x] & pivot1Mask_[x + y] & pivot2Mask_[n_ - 1 - x + y]) {
                if (y == n_ - 1) {
                    ++resultCount_;
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
    int resultCount_;
};

int main(int argc, char* argv[])
{
	int n;
	cin >> n;

    Solution solution;
    std::cout << solution.totalNQueens(n) << std::endl;

    return 0;
}
