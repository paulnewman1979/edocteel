#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            while ((j >= i)
                && (nums[j] == val) ) {
                -- j;
            }

            while ( (i <= j)
                && (nums[i] != val) ) {
                ++ i;
            }

            if (i < j) {
                nums[i] = nums[j];
                ++ i;
                -- j;
            }
        }

        nums.resize(i);
        return i;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums;
    int val;
    int num;

    cin >> val;

    cin >> num;
    while (num != -999999)
    {
        nums.push_back(num);
        cin >> num;
    }

    Solution solution;
    int size = solution.removeElement(nums, val);

    cout << size << endl;
}
