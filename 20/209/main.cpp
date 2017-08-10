#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minSize = nums.size() + 1;
        int start = 0;
        int end = 0;
        int sum = 0;
        int size = 0;
        while (end < nums.size()) {
            sum += nums[end];
            ++end;
            ++size;
            if (sum >= s) {
                if (size < minSize) {
                    minSize = size;
                }

                while (sum >= s) {
                    sum -= nums[start];
                    ++start;
                    --size;
                    if (sum >= s) {
                        if (size < minSize) {
                            minSize = size;
                        }
                    }
                }
            }
        }

        if (minSize == nums.size() + 1) {
            return 0;
        }
        
        return minSize;
    }
};

int main(int argc, char* argv[])
{
	int s;
    int num;
	vector<int> nums;

    cin >> s;
	cin >> num;
	while (num != -999999) {
		nums.push_back(num);
		cin >> num;
	}

    Solution solution;
	cout << solution.minSubArrayLen(s, nums) << endl;

    return 0;
}
