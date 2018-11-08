#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        const int size = A.size();
        vector< pair<int, int> > sortB;
        vector< pair<int, int> > sortA;
        int i, j, k;
        vector<int> result(size, -1);
        for (i = 0; i < size; ++i) {
            sortB.push_back(make_pair(B[i], i));
        }
        sort(A.begin(), A.end());
        sort(sortB.begin(), sortB.end(), PairComp); 

        i = size - 1;
        j = size - 1;
        k = 0;
        while (j >= 0) {
            if (sortB[j].first < A[i]) {
                result[sortB[j].second] = A[i];
                --j;
                --i;
            } else {
                result[sortB[j].second] = A[k];
                --j;
                ++k;
            }
        }
        return result;
    }

private:
    static bool PairComp(pair<int, int>& a, pair<int, int>& b) {
        return (a.first < b.first);
    }
};

int main(int argc, char* argv[])
{
    // input
	vector<int> A;
	vector<int> B;

    // temp variable
	int n;
    int value;

    // process input
	cin >> n;
	while (n-- > 0) {
        cin >> value;
        A.push_back(value);
	}

	cin >> n;
	while (n-- > 0) {
        cin >> value;
        B.push_back(value);
	}

    // solution
    Solution solution;
	vector<int> result = solution.advantageCount(A, B);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
