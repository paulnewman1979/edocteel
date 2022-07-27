#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        return findMin(nums, start, end);
    }

private:
    int findMin(vector<int>& nums, int start, int end) {
        if (end <= start + 1) {
            return (nums[start] > nums[end]) ? nums[end] : nums[start];
        }

        if (nums[start] < nums[end]) {
            return nums[start];
        } else {
            int median = (start + end) / 2;
            if (nums[median] > nums[start]) {
                return findMin(nums, median + 1, end);
            } else if (nums[median] < nums[start]) {
                return findMin(nums, start, median);
            } else {
                int least = findMin(nums, start, median);
                if (least < nums[start]) {
                    return least;
                } else if (least > nums[start]) {
                    return findMin(nums, median + 1, end);
                } else {
                    int leastNew = findMin(nums, median + 1, end);
                    return (leastNew > least) ? least : leastNew;
                }
            }
        }
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
    cout << solution.findMin(nums) << endl;

    return 0;
}
