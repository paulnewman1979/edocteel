#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const int base = 30000;
        int maximalDistance = 0;
        int i, j;
        unordered_set<uint32_t> obstaclesSet;
        for (i = 0; i < obstacles.size(); ++i) {
            //cout << "\tobs, " << obstacles[i][0] << " " << obstacles[i][1] << endl;
            obstaclesSet.insert(((obstacles[i][0] + base)<<16) + obstacles[i][1] + base);
        }

        int x = 0, y = 0, direction = 0;
        for (i = 0; i < commands.size(); ++i) {
            //cout << "step " << i << endl;
            //cout << "\tx=" << x << "\ty=" << y << "\tdir="<< direction << endl;
            //cout << "\tcommand=" << commands[i] << endl;
            switch(commands[i]) {
            case -2:
                direction = (direction + 3) % 4;
                break;
            case -1:
                direction = (direction + 1) % 4;
                break;
            default:
                switch(direction) {
                case 0:
                    for (j = y + 1; j <= y + commands[i]; ++j) {
                        if (obstaclesSet.count(((x + base)<<16) + j + base) > 0) {
                            //cout << "\tfail, " << x << " " << j << endl;
                            break;
                        }
                        //cout << "\tsucc, " << x << " " << j << endl;
                    }
                    y = j - 1;
                    break;
                case 1:
                    for (j = x + 1; j <= x + commands[i]; ++j) {
                        if (obstaclesSet.count(((j + base)<<16) + y + base) > 0) {
                            //cout << "\tfail, " << j << " " << y << endl;
                            break;
                        }
                        //cout << "\tsucc, " << j << " " << y << endl;
                    }
                    x = j - 1;
                    break;
                case 2:
                    for (j = y - 1; j >= y - commands[i]; --j) {
                        if (obstaclesSet.count(((x + base)<<16) + j + base) > 0) {
                            //cout << "\tfail, " << x << " " << j << endl;
                            break;
                        }
                        //cout << "\tsucc, " << x << " " << j << endl;
                    }
                    y = j + 1;
                    break;
                case 3:
                    for (j = x - 1; j >= x - commands[i]; --j) {
                        if (obstaclesSet.count(((j + base)<<16) + y + base) > 0) {
                            //cout << "\tfail, " << j << " " << y << endl;
                            break;
                        }
                        //cout << "\tsucc, " << j << " " << y << endl;
                    }
                    x = j + 1;
                    break;
                }
                if (x * x + y * y > maximalDistance) {
                    maximalDistance = x * x + y * y;
                }
            }
            //cout << "\tend, x=" << x << "\ty=" << y << "\tdir=" << direction << endl;
        }

        return maximalDistance;
    }
};

int main(int argc, char* argv[])
{
    vector< vector<int> > obstacles;
    vector<int> commands;

    int n;
    int nn;
    int value;
    vector<int> values;

    cin >> n;
    while (n-- > 0) {
        cin >> value;
        commands.push_back(value);
    }

    cin >> n;
    while (--n >= 0) {
        cin >> nn;
        values.clear();
        while (nn-- > 0) {
            cin >> value;
            values.push_back(value);
        }
        obstacles.push_back(values);
    }

    
    Solution solution;
    cout << solution.robotSim(commands, obstacles) << endl;

    return 0;
}
