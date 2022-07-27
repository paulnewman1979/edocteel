#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }

        int min = nums[0];
        int max = nums[0];
        int i, j;
        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] < min) {
                min = nums[i];
            }
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        int gap = (max - min) / (nums.size() + 1);
        if (0 == gap) gap = 1;
        int interval = (max - min) / gap + 1;
        vector<int> gapMin(interval, 0);
        vector<int> gapMax(interval, 0);
        int index;
        for (i = 0; i < nums.size(); ++i) {
            index = (nums[i] - min) / gap;
            if (gapMin[index] == 0) {
                gapMin[index] = nums[i];
                gapMax[index] = nums[i];
            } else {
                if (gapMin[index] > nums[i]) {
                    gapMin[index] = nums[i];
                }
                if (gapMax[index] < nums[i]) {
                    gapMax[index] = nums[i];
                }
            }
        }

        max = 0;
        for (i = 0; i < interval;) {
            j = i + 1;
            while ((j < interval) && (gapMin[j] == 0)) {
                ++j;
            }
            if (j == interval) {
                i = interval;
            } else {
                if (gapMin[j] - gapMax[i] > max) {
                    max = gapMin[j] - gapMax[i];
                } 
                i = j;
            }
        }
        
        return max;
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
    cout << solution.maximumGap(nums) << endl;

    return 0;
}
