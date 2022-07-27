#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return (nums[1] > nums[0]) ? nums[1] : nums[0];
        }

        // by position 0
        int result0 = nums[0];
        int result1 = nums[0];
        int result2 = 0;
        int result3 = nums[1];
        int result;

        int index = 2;
        while (index + 1 < nums.size()) {
            if (index % 2 == 0) {
                result0 = (result0 + nums[index] > result1) ? (result0 + nums[index]) : result1;
                result2 = (result2 + nums[index] > result3) ? (result2 + nums[index]) : result3;
                //cout << index << " : result0: " <<  result0 << endl;
                //cout << index << " : result2: " <<  result2 << endl;
            } else {
                result1 = (result1 + nums[index] > result0) ? (result1 + nums[index]) : result0;
                result3 = (result3 + nums[index] > result2) ? (result3 + nums[index]) : result2;
                //cout << index << " : result1: " <<  result1 << endl;
                //cout << index << " : result3: " <<  result3 << endl;
            }
            ++index;
        }

        //cout << index << endl;
        if (index % 2 == 0) {
            result = (result2 + nums[index] > result3) ? (result2 + nums[index]) : result3;
            if (result1 > result) {
                result = result1;
            }
        } else {
            result = (result3 + nums[index] > result2) ? (result3 + nums[index]) : result2;
            if (result0 > result) {
                result = result0;
            }
        }
        return result;
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
    cout << solution.rob(nums) << endl;

    return 0;
}
