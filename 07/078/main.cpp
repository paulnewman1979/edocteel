#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curResult;
        vector< vector<int> > result;
        int i, j;
        result.push_back(curResult);
        curResult.push_back(nums[0]);
        result.push_back(curResult);
        for (i = 1; i < nums.size(); ++i) {
            int size = result.size();
            for (j = 0; j < size; ++j) {
                result.push_back(result[j]);
                result[j + size].push_back(nums[i]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int value;
    vector<int> nums;

    cin >> n;
    while (n > 0) {
        cin >> value;
        nums.push_back(value);
        --n;
    }
        
    Solution solution;
    vector< vector<int> > result = solution.subsets(nums);
    for (int i=0; i<result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
