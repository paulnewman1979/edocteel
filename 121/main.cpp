#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (0 == size) {
            return 0;
        }
        
        int curMax = 0;
        int curMin = prices[0];
        for (int i=1; i<size; ++i) {
            if (curMin > prices[i]) {
                curMin = prices[i];
            } else if (prices[i] - curMin > curMax) {
                curMax = prices[i] - curMin;
            }
        }
        
        return curMax;
    }
};

int main(int argc, char* argv[])
{
	int n;
	vector<int> prices;

	cin >> n;
	while (n != -999999) {
		prices.push_back(n);
		cin >> n;
	}
		
    Solution solution;
	cout << solution.maxProfit(prices) << endl;

    return 0;
}
