#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maxDistToClosest(const vector<int>& seats) {
        int i = 0, j;
        while (seats[i] == 0) {
            ++i;
        }
        int maxGap = i;
        j = i + 1;
        while (j < seats.size()) {
            if (seats[j] == 1) {
                if ((j - i) / 2 > maxGap) {
                    maxGap = (j - i) / 2;
                }
                i = j;
            }
            ++j;
        }
        if (seats[j - 1] == 0) {
            if (j - 1 - i > maxGap) {
                maxGap = j - 1 - i;
            }
        }
        return maxGap;
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
    cout << solution.maxDistToClosest(values) << endl;

    return 0;
}
