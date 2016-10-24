#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i=0;
        int total = 0;
        for (i=0; i<gas.size(); ++i) {
            total += gas[i] - cost[i];
        }
        if (total < 0) {
            return -1;
        }
        
        total = 0;
        int curStart = 0;
        for (i=0; i<gas.size(); ++i) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                curStart = i + 1;
            }
        }
        
        return curStart;
    }
};

int main(int argc, char* argv[])
{
	int n;
	vector<int> gas;
	vector<int> cost;

	cin >> n;
	while (n != -999999) {
		gas.push_back(n);
		cin >> n;
	}

	cin >> n;
	while (n != -999999) {
		cost.push_back(n);
		cin >> n;
	}

    Solution solution;
	cout << solution.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
