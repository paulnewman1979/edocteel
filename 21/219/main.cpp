#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) numSet[nums[i - k - 1]]--;
            numSet[nums[i]]++;
            if (numSet[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int value;
    int k;
    vector<int> values;

    cin >> k;
    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.containsNearbyDuplicate(values, k) ? "true" : "false") << endl;

    return 0;
}
