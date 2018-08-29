#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return 0;
        }

        int i = 0;
        int j = nums.size() - 1;
        int l, m, pivot;
        while (i + 1 < j) {
            //cout << i  << "\t" << nums[i] << endl;
            //cout << j  << "\t" << nums[j] << endl;
            //cout << k  << endl << endl;
            pivot = nums[j];
            l = i;
            m = j - 1;
            while (l < m) {
                if (nums[l] >= pivot) {
                    ++l;
                } else if (nums[m] < pivot) {
                    --m;
                } else {
                    swap(nums[l], nums[m]);
                    ++l;
                    --m;
                }
            }
    
            if (nums[l] >= pivot) {
                ++l;
            }
            if (l - i + 1 == k) {
                return pivot;
            } else if (l - i + 1 > k) {
                j = l - 1;
            } else {
                k -= l - i + 1;
                i = l;
                --j;
            }
        }

        if (i == j) {
            return nums[i];
        } else {
            //cout << k << endl;
            //cout << ((k==1)? "true" : "false") << endl;
            //cout << ((nums[i] > nums[j])? "true" : "false") << endl;
            //cout << ((k==2)? "true" : "false") << endl;
            //cout << ((nums[j] > nums[i])? "true" : "false") << endl;

            return (((k==1) && (nums[i] > nums[j])) || ((k==2) && (nums[j] > nums[i]))) ? nums[i] : nums[j];
        }
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> nums;
    int num;
    int k;

    cin >> k;
    cin >> n;
    while (n > 0) {
        cin >> num;
        nums.push_back(num);
        --n;
    }

    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;

    return 0;
}
