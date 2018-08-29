#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (numSet.find(nums[i]) != numSet.end()) {
                return true;
            }
            numSet.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int value;
    vector<int> values;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.containsDuplicate(values) ? "true" : "false") << endl;

    return 0;
}
