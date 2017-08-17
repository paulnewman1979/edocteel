#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        int i;
        for (i=result.size()-1; i>=0; --i) {
            ++ result[i];
            if (result[i] >= 10) {
                result[i] -= 10;
            } else {
                break;
            }
        }
        
        if (i == -1) {
            result.push_back(result[result.size()-1]);
            for (i=result.size()-1; i>0; --i) {
                result[i] = result[i-1];
            }
            result[0] = 1;
        }
        
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> digits;
    vector<int> result;

    cin >> n;
    while (n != -999999) {
        digits.push_back(n);
        cin >> n;
    }
        
    Solution solution;
    result = solution.plusOne(digits);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
