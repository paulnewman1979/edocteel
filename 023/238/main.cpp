#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int total = 1;
        unsigned int i = 0;
        int zeroCount = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                total *= nums[i];
            }
        }
        if (zeroCount > 1) {
            for (i = 0; i < nums.size(); ++i) {
                result.push_back(0);
            }
        } else if (zeroCount == 0) {
            for (i = 0; i < nums.size(); ++i) {
                result.push_back(total / nums[i]);
            }
        } else {
            for (i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    result.push_back(total);
                } else {
                    result.push_back(0);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> digits;
    vector<int> result;

    cin >> n;
    while (n != -999999) {
        digits.push_back(n);
        cin >> n;
    }
        
    Solution solution;
    result = solution.productExceptSelf(digits);
    for (unsigned int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
