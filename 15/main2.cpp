#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > results;
        vector<int> three;
        three.resize(3);
        sort(nums.begin(), nums.end());

        int i;
        int j;
        int k;
        for (i=0; i+2<nums.size(); ++i) {
            if ((i>=1) && (nums[i] == nums[i-1])) {
                continue;
            }

            k = nums.size() - 1;
            for (j=i+1; j+1<nums.size(); ++j) {
                if ((j > i+1) && (nums[j] == nums[j-1])) {
                    continue;
                }

                int value = nums[i] + nums[j];

                while ((k>j) && (value + nums[k] > 0)) {
                    k--;
                }
                if (k <= j) {
                }
                else if (value + nums[k] == 0) {
                    three[0] = nums[i];
                    three[1] = nums[j];
                    three[2] = nums[k];
                    results.push_back(three);
                }
                else if (k < nums.size() - 1) {
                    k++;
                }
            }
        }
        
        return results;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums;
    int num;
    cin >> num;
    while (num != -999999)
    {
        nums.push_back(num);
        cin >> num;
    }

    Solution solution;
    vector< vector<int> > results = solution.threeSum(nums);
    for (int i=0; i<results.size(); ++i)
    {
        cout << results[i][0] << "\t" << results[i][1] << "\t" << results[i][2] << endl;
    }
}
