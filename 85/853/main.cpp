#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>&b) {
    return (a.first > b.first);
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 0) return 0;

        vector<pair<int, int>> posSpeed(position.size());
        int i;
        for (i = 0; i < position.size(); ++i) {
            posSpeed[i].first = position[i];
            posSpeed[i].second = speed[i];
        }
        sort(posSpeed.begin(), posSpeed.end(), compare);
        int groupCount = 0;
        int curGroupIndex = 0;
        for (i = 1; i < posSpeed.size(); ++i) {
            long long int mul1 = target - posSpeed[i].first;
            mul1 *= posSpeed[curGroupIndex].second;
            long long int mul2 = target - posSpeed[curGroupIndex].first;
            mul2 *= posSpeed[i].second;
            if (mul1 > mul2) {
                ++groupCount;
                curGroupIndex = i;
            }
        }
        ++groupCount;
        return groupCount;
    }
};

int main(int argc, char* argv[])
{
    int target;
    int n;
    vector<int> position;
    vector<int> speed;
    int value;

    cin >> target;

    cin >> n;
    while (n > 0) {
        cin >> value;
        position.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        speed.push_back(value);
        --n;
    }

        
    Solution solution;
    cout << solution.carFleet(target, position, speed) << endl;

    return 0;
}
