#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> numSet;
        unordered_set<int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            iter = numSet.find(nums[i]);
            if (iter != numSet.end()) {
                numSet.erase(iter);
            } else{
                numSet.insert(nums[i]);
            }
        }

        iter = numSet.begin();
        while (iter != numSet.end()) {
            result.push_back(*iter);
            ++iter;
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> nums;
    vector<int> result;
    int num;

    cin >> n;
    while (n > 0) {
        cin >> num;
        nums.push_back(num);
        --n;
    }
        
    Solution solution;
    result = solution.singleNumber(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
