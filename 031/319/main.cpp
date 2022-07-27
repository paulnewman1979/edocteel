#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        int i = 1;
        while (i * i <= n) {
            ++ count;
            ++ i;
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
