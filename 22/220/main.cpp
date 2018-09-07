#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include <iterator>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0) return false;
        multiset<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            //cout << "checking i=" << i << ", nums[i]=" << nums[i] << endl;
            if (i > k) st.erase(st.find(nums[i - k - 1]));
            auto it = st.lower_bound(nums[i] - t);
            if (it != st.end()) {
                //cout << "\tfound " << *it << ", compare with " << nums[i] << endl;
                if (*it < nums[i]) {
                    //cout << "\tless: nums[i] =" << nums[i] << ", *it + t =" << (*it + t) << endl;
                    if (nums[i] <= *it + t) return true;
                } else {
                    //cout << "\tmore: *lt =" << *it << ", nums[i] =" << (nums[i] + t) << endl;
                    if (*it <= nums[i] + t) return true;
                }
            }
            st.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    int k;
    int t;
    int n;
    int num;
    vector<int> nums;

    cin >> k;
    cin >> t;
    cin >> n;
    while (n > 0) {
        cin >> num;
        nums.push_back(num);
        --n;
    }
        
    Solution solution;
    cout << (solution.containsNearbyAlmostDuplicate(nums, k, t) ? "true" : "false") << endl;

    return 0;
}
