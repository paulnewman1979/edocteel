#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numSet;
        for (int i = 0; i < nums.size(); ++i) {
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
