#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> mark(nums.size(), false);
        int i, j;
        mark[0] = true;
        for (i = 0; i < nums.size(); ++i) {
            if (mark[i]) {
                for (j = 1; j <= nums[i]; ++j) {
                    mark[i + j] = true;
                }
            }
        }

        return mark[nums.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    int n;
    int value;
    vector<int> nums;

    cin >> n;
    while (n > 0) {
        cin >> value;
        nums.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.canJump(nums) ? "true" : "false") << endl;

    return 0;
}
