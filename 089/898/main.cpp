#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int i;
        unordered_set<int> orSetA;
        unordered_set<int> orSetB;
        unordered_set<int>::const_iterator iter;

        orSetA.insert(A[0]);
        for (i = 1; i < A.size(); ++i) {
            // B
            orSetB.insert(orSetA.begin(), orSetA.end());

            // A
            unordered_set<int> orSetTemp;
            iter = orSetA.begin();
            while (iter != orSetA.end()) {
                orSetTemp.insert((*iter) | A[i]);
                ++iter;
            }
            orSetTemp.insert(A[i]);
            orSetA.swap(orSetTemp);
        }

        orSetA.insert(orSetB.begin(), orSetB.end());

        return orSetA.size();
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> nums;
    int num;

    cin >> n;
    while (n > 0) {
        cin >> num;
        nums.push_back(num);
        --n;
    }
        
    Solution solution;
    cout << solution.subarrayBitwiseORs(nums) << endl;

    return 0;
}
