#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int result = 0;
        int count;
        int i = 0, j, k;
        vector<int> ageMap(121, 0);
        vector<int> ageSum(121, 0);
        for (i = 0; i < ages.size(); ++i) {
            ageMap[ages[i]]++;
        }

        for (i = 1; i <= 120; ++i) {
            ageSum[i] = ageSum[i - 1] + ageMap[i];
        }

        for (i = 1; i <= 120; ++i) {
            j = i / 2 + 8;
            k = i;
            if ((ageMap[i] > 0) && (j <= k)) {
                count = ageSum[k] - ageSum[j - 1];
                if ((j <= i) && (i <= k)) {
                    --count;
                }
                result += ageMap[i] * count;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<int> values;
    int value;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.numFriendRequests(values) << endl;

    return 0;
}
