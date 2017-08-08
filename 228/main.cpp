#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() > 0) {
            int start = nums[0];
            int end = nums[0];
            for (size_t i = 1; i < nums.size(); i++) {
                if (nums[i] - end == 1) {
                    end = nums[i];
                } else {
                    if (start == end) {
                        stringstream oss;
                        oss << start;
                        result.push_back(oss.str());
                    } else {
                        stringstream oss;
                        oss << start << "->" << end;
                        result.push_back(oss.str());
                    }
                    start = nums[i];
                    end = nums[i];
                }
            }
            if (start == end) {
                stringstream oss;
                oss << start;
                result.push_back(oss.str());
            } else {
                stringstream oss;
                oss << start << "->" << end;
                result.push_back(oss.str());
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
	int n;
	vector<int> digits;
	vector<string> result;

	cin >> n;
	while (n != -999999) {
		digits.push_back(n);
		cin >> n;
	}
		
    Solution solution;
	result = solution.summaryRanges(digits);
	for (int i=0; i<result.size(); ++i) {
		cout << result[i] << endl;
	}

    return 0;
}
