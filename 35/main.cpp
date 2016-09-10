#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (0 == nums.size()) {
            return 0;
        } else if (target <= nums[0]) {
            return 0;
        } else if (target > nums[nums.size() - 1]) {
            return nums.size();
        } else if (target == nums[nums.size() - 1]) {
            return nums.size() - 1;
        }
        
        int lower = 0;
        int higher = nums.size() - 1;
        int median;
        while (lower + 1 < higher) {
            median = (lower + higher + 1) / 2;
            if (nums[median] == target) {
                return median;
            } else if (target < nums[median]) {
                higher = median;
            } else {
                lower = median;
            }
        }
        return lower + 1;
    }
};

int main(int argc, char* argv[])
{
	vector<int> nums;
	int target;
	int num;

	cin >> target;
	cin >> num;
	while (num != -999999) {
		nums.push_back(num);
		cin >> num;
	}

    Solution solution;
	cout << solution.searchInsert(nums, target) << endl;

    return 0;
}
