#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count1 = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            while ((i <= j) &&
                (nums[i] == 0) ) {
                ++ i;
            }
            
            while ((i <= j) &&
                (nums[j] != 0)) {
                if (nums[j] == 1) {
                    ++ count1;
                }
                -- j;
            }
            
            if (i < j) {
                if (nums[i] == 1) {
                    ++ count1;
                }
                nums[i] = 0;
                nums[j] = 2;
                ++ i;
                
                -- j;
            }
        }
        
        if (nums[i] == 0) {
            ++ i;
        }
        
        for (j=i; j<i+count1; ++j) {
            nums[j] = 1;
        }
        
        for (; j<nums.size(); ++j) {
            nums[j] = 2;
        }
    }
};

int main(int argc, char* argv[])
{
	vector<int> nums;
	int n;

	cin >> n;
	while (n != -999999) {
		nums.push_back(n);
		cin >> n;
	}

    Solution solution;
	solution.sortColors(nums);
	for (int i=0; i<nums.size(); ++i) {
		cout << nums[i] << endl;
	}

    return 0;
}
