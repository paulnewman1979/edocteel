#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int m = 0, n = 0;
        unsigned int cm = 0, cn = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == m) ++cm;
            else if (nums[i] == n) ++cn;
            else if (0 == cm) m = nums[i], cm = 1;
            else if (0 == cn) n = nums[i], cn = 1;
            else --cm, -- cn;
        }
        cm = 0, cn = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == m) ++cm;
            else if (nums[i] == n) ++cn;
        }
        if (cm > nums.size() / 3) result.push_back(m);
        if (cn > nums.size() / 3) result.push_back(n);
        return result;
    }
};

int main(int argc, char* argv[])
{
	int n;
	vector<int> digits;
	vector<int> result;

	cin >> n;
	while (n != -999999) {
		digits.push_back(n);
		cin >> n;
	}
		
    Solution solution;
	result = solution.majorityElement(digits);
	for (size_t i=0; i<result.size(); ++i) {
		cout << result[i] << endl;
	}

    return 0;
}
