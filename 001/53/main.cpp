#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int sumMax = (nums.size()>0)?nums[0]:0;
		int i;
		for (i=0; i<nums.size(); ++i) {
			if (nums[i] >= 0) {
				sum += nums[i];
				if (sum > sumMax) {
					sumMax = sum;
				}
			} else {
				sum += nums[i];
				if (sum > sumMax) {
					sumMax = sum;
				}
				if (sum < 0) {
					sum = 0;
				}
			}
		}

		return sumMax;
    }
};

int main(int argc, char* argv[])
{
	vector<int> nums;
	int n;
	cin >> n;
	while (n != -999999) {
		nums.push_back(n);
		cin >> n;
	}

    Solution solution;
	cout << solution.maxSubArray(nums) << endl;

    return 0;
}
