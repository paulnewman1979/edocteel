#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while (j < nums.size()) {
            if (nums[j] != nums[i]) {
                if (j == i + 1) {
                    i = j + 1;
                    j = i + 1;
                } else {
                    swap(nums[i + 1], nums[j]);
                    i = i + 2;
                    ++j;
                }
            } else {
                ++j;
            }
        }

        return nums[nums.size() - 1];
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
    cout << solution.majorityElement(nums) << endl;

    return 0;
}
