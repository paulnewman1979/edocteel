#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int find(vector<int>& nums, int value, int j, int& k) {
        if (nums[k] <= value) {
            return nums[k] - value;
        }
        else if (nums[j] >= value) {
            k = j;
            return nums[j] - value;
        }

        while (k - j > 1) {
            int idx = (k + j + 1)/2;
            if (nums[idx] == value) {
                k = idx;
                return 0;
            }
            else if (nums[idx] < value) {
                j = idx;
            }
            else {
                k = idx;
            }
        }

        return ((nums[k]-value)>=(value-nums[j]))? (value-nums[j]):(nums[k]-value);
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int i, j, k;
        int sum;
        int min_sum = INT_MAX;

        sort(nums.begin(), nums.end());
        for (i=0; i+2<nums.size(); ++i) {
            if ((i>=1) && (nums[i] == nums[i-1])) {
                continue;
            }

            k = nums.size() - 1;
            for (j=i+1; j+1<nums.size(); ++j) {
                if ((j > i+1) && (nums[j] == nums[j-1])) {
                    continue;
                }

                int value = target - nums[i] - nums[j];
                sum = find(nums, value, j+1, k);
                if (sum == 0) {
                    return target;
                }
                else if (abs(sum) < abs(min_sum))
                {
                    min_sum = sum;
                }
            }
        }
        
        return min_sum + target;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums;
    int num;
    int target;
    cin >> target;

    cin >> num;
    while (num != -999999)
    {
        nums.push_back(num);
        cin >> num;
    }

    Solution solution;
    int result = solution.threeSumClosest(nums, target);
    cout << result << endl;
}
