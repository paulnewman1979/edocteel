#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> result;
        int i;
        int diff = 0;
        unordered_set<int> aset;
        for (i = 0; i < A.size(); ++i) {
            diff += A[i];
            aset.insert(A[i]);
        }
        for (i = 0; i < B.size(); ++i) {
            diff -= B[i];
        }
        diff = diff>>1;

        for (i = 0; i < B.size(); ++i) {
            if (aset.find(B[i] + diff) != aset.end()) {
                result.push_back(B[i] + diff);
                result.push_back(B[i]);
                break;
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> values1;
    vector<int> values2;
    int value;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values1.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        values2.push_back(value);
        --n;
    }
        
    Solution solution;
    vector<int> result = solution.fairCandySwap(values1, values2);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
