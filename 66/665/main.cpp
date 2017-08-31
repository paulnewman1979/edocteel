#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        unsigned int i = 0;
        unsigned int count = 0;
        unsigned int size = nums.size();
        if (size <= 2) {
            return true;
        }
        for (i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                ++count;
                if (count > 1) {
                    return false;
                } else if (i == 0) {
                } else if (i + 2 == size) {
                    return true;
                } else if (nums[i] <= nums[i + 2]) {
                    ++i;
                } else if (nums[i - 1] <= nums[i + 1]) {
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> nums;

    cin >> n;
    while (n != -999999) {
        nums.push_back(n);
        cin >> n;
    }
        
    Solution solution;
    cout << (solution.checkPossibility(nums) ? "true" : "false") << endl;

    return 0;
}
