#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        
        if (nums[0] > nums[1]) {
            return 0;
        }
        for (int i=1; i<nums.size()-1; ++i) {
            if ((nums[i] > nums[i-1]) &&
                (nums[i] > nums[i+1])) {
                return i;    
            }
        }
        return nums.size() - 1;
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
	cout << solution.findPeakElement(nums) << endl;

    return 0;
}
