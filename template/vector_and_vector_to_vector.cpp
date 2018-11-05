#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result;
        return result;
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
    cout << endl;

    return 0;
}
