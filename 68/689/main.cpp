#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct max1Record {
    max1Record() { sum = 0; }
    int sum;
    int i;
};

struct max2Record {
    max2Record() { sum = 0; }
    int sum;
    int i;
    int j;
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> sums;
        int i, max, curI, curJ, curL;
        int sum = 0;
        for (i = 0; i < k; ++i) sum += nums[i];
        sums.push_back(sum);
        for (i = 0; i + k < nums.size(); ++i) {
            sum += nums[i + k ] - nums[i];
            sums.push_back(sum);
        }

        // 
        max = 0;
        vector<max1Record> maxr1(sums.size(), max1Record());
        for (i = sums.size() - 1; i >= k + k; i--) {
            if (sums[i] > max) {
                max = sums[i];
                curI = i;
            }
            maxr1[i].sum = max;
            maxr1[i].i = curI;
        }

        //
        max = 0;
        curI = sums.size() - k - 1;
        vector<max2Record> maxr2(sums.size(), max2Record());
        for (i = sums.size() - k - 1; i >= k; i--) {
            if (sums[i] + maxr1[i + k].sum >= max) {
                max = sums[i] + maxr1[i + k].sum;
                curI = i;
                curJ = maxr1[i + k].i;
                maxr2[i].sum = max;
                maxr2[i].i = curI;
                maxr2[i].j = curJ;
            } else {
                maxr2[i].sum = maxr2[i + 1].sum;
                maxr2[i].i = curI;
                maxr2[i].j = curJ;
            }
        }

        //
        max = 0;
        curI = sums.size() - k - k - 1;
        for (i = sums.size() - k - k - 1; i >= 0; i--) {
            if (sums[i] + maxr2[i + k].sum >= max) {
                max = sums[i] + maxr2[i + k].sum;
                curI = i;
                curJ = maxr2[i + k].i;
                curL = maxr2[i + k].j;
            }
        }

        result.push_back(curI);
        result.push_back(curJ);
        result.push_back(curL);

        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int k;
    int num;
    vector<int> nums;
    vector<int> result;

    cin >> k;

    cin >> n;
    while (n > 0) {
        cin >> num;
        nums.push_back(num);
        --n;
    }
        
    Solution solution;
    result = solution.maxSumOfThreeSubarrays(nums, k);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
