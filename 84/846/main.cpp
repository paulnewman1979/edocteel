#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        unordered_map<int, int> count;
        int i, j;
        std::sort(hand.begin(), hand.end());
        for (i = 0; i < hand.size(); ++i) {
            count[hand[i]]++;
        }

        for (i = 0; i < hand.size(); ++i) {
            if (count[hand[i]] > 0) {
                for (j = hand[i] + 1; j < hand[i] + W; ++j) {
                    if (count[j] >= count[hand[i]]) {
                        count[j] -= count[hand[i]];
                    } else {
                        return false;
                    }
                }
                count[hand[i]] = 0;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    int W;

    int n;
    int value;
    vector<int> values;

    cin >> W;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.isNStraightHand(values, W) ? "true" : "false") << endl;

    return 0;
}
