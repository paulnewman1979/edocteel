#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        combineInner(1, n, k);
        return result;
    }

    void combineInner(int min, int max, int k) {
        if (0 == k) {
            result.push_back(curResult);
            return;
        }
        if (min > max) {
            return;
        }

        curResult.push_back(min);
        combineInner(min + 1, max, k - 1);
        curResult.pop_back();

        combineInner(min + 1, max, k);
    }

private:
    vector<int> curResult;
    vector< vector<int> > result;
};

int main(int argc, char* argv[])
{
	int n;
    int k;
	cin >> n;
    cin >> k;

    Solution solution;
    vector< vector<int> > result = solution.combine(n, k);
	for (unsigned int i = 0; i < result.size(); ++i) {
        for (unsigned int j = 0; j < result[i].size(); ++j) {
    		cout << result[i][j] << " ";
        }
        cout << endl;
	}

    return 0;
}
