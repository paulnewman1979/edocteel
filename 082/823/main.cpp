#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

long long MODULO = 1000000007;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, long long> aMap;
        unordered_map<int, long long>::iterator iter;
        int i, j;
        for (i = 0; i < A.size(); ++i) {
            aMap[A[i]] = 1;
        }
        long long product;
        for (i = 0; i < A.size(); ++i) {
            for (j = 0; j < i; ++j) {
                product = ((long long)A[i]) * A[j];
                iter = aMap.find(product);
                if (iter != aMap.end()) {
                    iter->second += aMap[A[i]] * aMap[A[j]] * 2;
                    iter->second %= MODULO;
                } else if (product > A[A.size() - 1]) {
                    break;
                }
            }
            product = ((long long)A[i]) * A[i];
            iter = aMap.find(product);
            if (iter != aMap.end()) {
                iter->second += aMap[A[i]] * aMap[A[i]];
            }
        }

        long long sum = 0;
        iter = aMap.begin();
        while (iter != aMap.end()) {
            sum += iter->second;
            sum %= MODULO;
            ++iter;
        }
        return sum;
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
    cout << solution.numFactoredBinaryTrees(values) << endl;

    return 0;
}
