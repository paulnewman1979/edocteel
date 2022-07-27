#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        if ((stations.size() == 0) || startFuel < stations[0][0]) return -1;

        int i, j;
        long long int distance;
        vector<long long int> stopFuel;
        stopFuel.push_back(startFuel - stations[0][0]);
        stopFuel.push_back(startFuel - stations[0][0] + stations[0][1]);
        /*
        cout << "stopFuel[0]=" << stopFuel[0] << endl;
        cout << "stopFuel[1]=" << stopFuel[1] << endl;
        cout << endl;
        */

        for (i = 1; i < stations.size(); ++i) {
            // check
            distance = stations[i][0] - stations[i - 1][0];
            if (stopFuel[i] < distance) return -1;
            stopFuel.push_back(stopFuel[i] - distance + stations[i][1]);

            for (j = i; j > 0; --j) {
                if (stopFuel[j] >= distance) {
                    if ((stopFuel[j - 1] >= distance) &&
                            (stopFuel[j] < stopFuel[j - 1] + stations[i][1])) {
                        stopFuel[j] = stopFuel[j - 1] + stations[i][1] - distance;
                    } else {
                        stopFuel[j] -= distance;
                    }
                } else {
                    stopFuel[j] -= distance;
                }
            }
            stopFuel[0] -= distance;

            /*
            for (j = 0; j <= i + 1; j++) {
                cout << "stopFuel[" << j << "]=" << stopFuel[j] << endl;
            }
            cout << endl;
            */
        }

        distance = target - stations.back()[0];
        for (i = 0; i <= stations.size(); ++i) {
            if (stopFuel[i] >= distance) {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    // input
    int target;
    int startFuel;
    vector< vector<int> > valueGrid;

    // variable
    int n;
    int nn;
    vector<int> valueLine;
    int value;

    // input
    cin >> target;
    cin >> startFuel;
    cin >> n;
    while (n-- > 0) {
        cin >> nn;
        valueLine.clear();
        while (nn-- > 0) {
            cin >> value;
            valueLine.push_back(value);
        }
        valueGrid.push_back(valueLine);
    }

    Solution solution;
    cout << solution.minRefuelStops(target, startFuel, valueGrid) << endl;

    return 0;
}
