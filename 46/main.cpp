#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums)
	{
		vector< vector<int> > results;
		if (0 == nums.size()) {
			return results;
		} else if (1 == nums.size()) {
			results.push_back(vector<int>(nums[0], 1));
			return results;
		} else {
			vector<bool> marks(nums.size(), false);
			vector<int> result;

			int i=0;
			for (i=0; i<nums.size(); ++i) {
				marks[i] = true;
				result.push_back(nums[i]);
				permute(results, nums, result, marks, nums.size() - 1);
				result.pop_back();
				marks[i] = false;
			}
			return results;
		}
    }

	void permute(vector< vector<int> >& results,
				const vector<int>& nums,
				vector<int>& result,
				vector<bool>& marks,
				const int count)
	{
		int i;
		for (i=0; i<marks.size(); ++i) {
			if (marks[i] == false) {
				if (1 == count) {
					result.push_back(nums[i]);
					results.push_back(result);
					result.pop_back();
					return;
				} else {
					result.push_back(nums[i]);
					marks[i] = true;
					permute(results, nums, result, marks, count-1);
					marks[i] = false;
					result.pop_back();
				}
			}
		}
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
	results = solution.permute(nums);
	for (int i=0; i<results.size(); ++i) {
		for (int j=0; j<results[i].size(); ++j) {
			cout << results[i][j] << "\t";
		}
		cout << endl;
	}

    return 0;
}
