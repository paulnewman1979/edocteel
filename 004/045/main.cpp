#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int cur = 0;
        int max = nums[0];
        int nextMax = 0;
        int steps = 1;
        while (max < nums.size() - 1) {
            ++ cur;
            nextMax = cur + nums[cur];
            while (cur <= max) {
                if (nextMax < cur + nums[cur]) {
                    nextMax = cur + nums[cur];
                }
                ++ cur;
            }
            ++ steps;
            cur = max;
            max = nextMax;
        }

        return steps;
    }
};

int main(int argc, char* argv[])
{
	int n;
	vector<int> nums;
	vector< vector<int> > results;

	cin >> n;
	while (n != -999999) {
		nums.push_back(n);
		cin >> n;
	}

    Solution solution;
	cout << solution.jump(nums) << endl;

    return 0;
}
