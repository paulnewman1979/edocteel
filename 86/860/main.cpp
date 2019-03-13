#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int A = 0, B = 0;
        for (int i = 0; i < bills.size(); ++i) {
            switch(bills[i]) {
              case 5:
                ++A;
                break;
              case 10:
                if (A < 1) {
                    return false;
                } else {
                    --A;
                    ++B;
                }
                break;
              default:
                if (B < 1) {
                    if (A < 3) {
                        return false;
                    } else {
                        A -= 3;
                    }
                } else {
                    if (A < 1) {
                        return false;
                    } else {
                        --B;
                        --A;
                    }
                } 
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int value;
    vector<int> values;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.lemonadeChange(values) ? "true" : "false") << endl;

    return 0;
}
