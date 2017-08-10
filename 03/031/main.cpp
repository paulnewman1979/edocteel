#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int i;
        int j;
        int t;
        for (i=nums.size()-1; i>0; --i) {
            if (nums[i-1] < nums[i]) {
                break;
            }
        }
        if (0 == i) {
            j = nums.size() - 1;
            while (i < j) {
                t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                ++ i;
                -- j;
            }
        } else {
            j = i;
            while ((j<nums.size())
                    && (nums[j]>nums[i-1])) {
                ++ j;
            }
            -- j;

            t = nums[i-1];
            nums[i-1] = nums[j];
            nums[j] = t;
            
            j = nums.size() - 1;
            while (i<j) {
                t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                ++ i;
                -- j;
            }
        }
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
    solution.nextPermutation(nums);
    for (int i=0; i<nums.size(); ++i) {
        cout << nums[i] << endl;
    }
}
