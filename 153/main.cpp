#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		if (0 == nums.size()) {
			return 0;
		} else if (nums[nums.size() - 1] > nums[0]) {
			return nums[0];
		}
		int start = 0;
		int end = nums.size() - 1;
		int median;
		while (start + 1 < end) {
			median = (start + end + 1) / 2;
			if (nums[median] > nums[start]) {
				start = median;
			} else {
				end = median;
			}
		}
		return nums[end];
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
	cout << solution.findMin(nums) << endl;

    return 0;
}
