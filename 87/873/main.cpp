#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int i, j;
        unordered_set<int> aSet;
        for (i = 0; i < A.size(); ++i) {
            aSet.insert(A[i]);
        }
        int nextValue;
        int maxResultSize = 0;
        vector<int> tmpResult;
        for (i = 0; i + 1 < A.size(); ++i) {
            for (j = i + 1; j < A.size(); ++j) {
                if (aSet.find(A[i] + A[j]) != aSet.end()) {
                    tmpResult.clear();
                    tmpResult.push_back(A[i]);
                    tmpResult.push_back(A[j]);
                    tmpResult.push_back(A[i] + A[j]);
                    nextValue = A[i] + A[j] + A[j];
                    while (aSet.find(nextValue) != aSet.end()) {
                        tmpResult.push_back(nextValue);
                        nextValue += tmpResult[tmpResult.size() - 2];
                    }

                    if (tmpResult.size() > maxResultSize) {
                        maxResultSize = tmpResult.size();
                    }
                }
            }
        }
        return maxResultSize;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> values;
    int value;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.lenLongestFibSubseq(values) << endl;

    return 0;
}
