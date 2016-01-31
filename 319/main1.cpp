#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> nums;
        nums.resize(n, 0);
        for (int i=2; i<=n; ++i) {
            for (int j=i; j<=n; j+=i) {
                nums[j-1] = 1 - nums[j-1];
            }
        }
        int count = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] == 0) {
                ++ count;
            }
        }
        return count;
    }
};

int main(int argc, char* argv[]) {
    int num;
    cin >> num;
    Solution solution;
    num = solution.bulbSwitch(num);
    cout << num << endl;
}
