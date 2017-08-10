#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int neg = 0;
        int pos = 0;
        int max = nums[0];
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == 0) {
                neg = 0;
                pos = 0;
                if (pos > max) {
                    max = pos;
                }
            } else if (nums[i] > 0) {
                pos = (pos > 0)? pos*nums[i] : nums[i];
                neg = (neg < 0)? neg*nums[i] : 0;
                if (pos > max) {
                    max = pos;
                }
            } else {
                int tmp = pos;
                if (neg < 0) {
                    pos = neg * nums[i];
                    if (pos > max) {
                        max = pos;
                    }
                } else {
                    pos = 0;
                }
                neg = (tmp > 0)? tmp * nums[i] : nums[i];
            }
        }
        
        return max;
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
	cout << solution.maxProduct(nums) << endl;

    return 0;
}
