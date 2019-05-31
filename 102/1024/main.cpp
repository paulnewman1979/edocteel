#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int i, j;
        unordered_map<int, vector<int> > startIndexMap;
        for (i = 0; i < clips.size(); ++i) {
            startIndexMap[clips[i][0]].push_back(i);
        }
        int end = 0;
        int cur = 0;
        bool updated = true;
        int count = 0;
        while ((updated) && (end < T)) {
            updated = false;
            int newEnd = end;
            for (; cur <= end; ++cur) {
                for (i = 0; i < startIndexMap[cur].size(); ++i) {
                    j = startIndexMap[cur][i];
                    if (clips[j][1] > newEnd) {
                        newEnd = clips[j][1];
                    }
                }
            }
            if (newEnd > end) {
                end = newEnd;
                ++count;
                updated = true;
            }
        }

        if (end >= T) {
            return count;
        } else {
            return -1;
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > clips;

    // variable
    int n;
    int nn;
    vector<int> valueLine;
    int value;

    // input
    int T;
    cin >> T;

    cin >> n;
    while (n-- > 0) {
        cin >> nn;
        valueLine.clear();
        while (nn-- > 0) {
            cin >> value;
            valueLine.push_back(value);
        }
        clips.push_back(valueLine);
    }

    Solution solution;
    cout << solution.videoStitching(clips, T) << endl;

    return 0;
}
