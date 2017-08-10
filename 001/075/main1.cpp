#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[] = {0, 0, 0};
        int i=0;
        for (i=0; i<nums.size(); ++i) {
            ++ count[nums[i]];
        }
        for (i=0; i<count[0]; ++i) {
            nums[i] = 0;
        }
        for (i=count[0]; i<count[0] + count[1]; ++i) {
            nums[i] = 1;
        }
        for (i=count[0] + count[1]; i<nums.size(); ++i) {
            nums[i] = 2;
        }
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
	solution.sortColors(nums);
	for (int i=0; i<nums.size(); ++i) {
		cout << nums[i] << endl;
	}

    return 0;
}
