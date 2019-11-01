#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

typedef pair<int, int> PosSpeed;

struct hash_pair {
    size_t operator() (const PosSpeed& posSpeed) const {
        auto hash1 = hash<int>{}(posSpeed.first);
        auto hash2 = hash<int>{}(posSpeed.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    int racecar(int target) {
        if (target == 0) {
            return 0;
        }

        int step = 0;
        int boundry = abs(target)<<1;
        int pos, speed;
        PosSpeed posSpeed;
        unordered_map<PosSpeed, int, hash_pair>::const_iterator iter;
        unordered_map<PosSpeed, int, hash_pair> posSpeedMap;
        posSpeedMap[make_pair(0, 1)] = 0;
        bool found = false;
        while (!found) {
            unordered_map<PosSpeed, int, hash_pair> tmp;
            tmp.clear();
            iter = posSpeedMap.begin();
            while (iter != posSpeedMap.end()) {
                if (iter->second == step) {
                    pos = iter->first.first;
                    speed = iter->first.second;
                    if (pos + speed == target) {
                        found = true;
                        break;
                    }
                    if (abs(pos + speed) < boundry) {
                        posSpeed.first = pos + speed;
                        posSpeed.second = (speed<<1);
                        if (posSpeedMap.find(posSpeed) == posSpeedMap.end()) {
                            tmp[posSpeed] = step + 1;
                        }
                    }
                    posSpeed.first = pos;
                    posSpeed.second = (speed > 0) ? -1 : 1;
                    if (posSpeedMap.find(posSpeed) == posSpeedMap.end()) {
                        tmp[posSpeed] = step + 1;
                    }
                }
                ++iter;
            }
            iter = tmp.begin();
            while (iter != tmp.end()) {
                posSpeedMap[iter->first] = iter->second;
                ++iter;
            }
            ++step;
        }

        return step;
    }
private:
    vector<int> speedLength;
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << solution.racecar(n) << endl;

    return 0;
}
