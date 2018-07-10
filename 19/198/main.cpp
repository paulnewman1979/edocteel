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
        int sum1 = 0;
        int sum2 = nums[0];
        int tmp;
        for (int i = 1; i < nums.size(); ++i) {
            sum1 = (sum1 + nums[i] > sum2) ? sum1 + nums[i] : sum2;
            tmp = sum1;
            sum1 = sum2;
            sum2 = tmp;
        }
        return sum2;
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
