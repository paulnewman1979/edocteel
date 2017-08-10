#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
    
        int i;    
        int size = nums.size();
        
        vector<int> marks(size + 1, 0);
        for (i=0; i<nums.size(); ++i) {
            if ((nums[i] > 0) &&
                (nums[i] <= size)) {
                marks[nums[i]-1] = 1;
            }
        }
        for (i=0; i<marks.size(); ++i) {
            if (marks[i] == 0) {
                return i + 1;
            }
        }
        
        return 0;
    }
};

int main(int argc, char* argv[])
{
	int n;
	vector<int> nums;
	vector< vector<int> > results;

	cin >> n;
	while (n != -999999) {
		nums.push_back(n);
		cin >> n;
	}

    Solution solution;
	cout << solution.firstMissingPositive(nums) << endl;

    return 0;
}
