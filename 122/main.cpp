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
        
		int profit = 0;
        for (int i=1; i<size; ++i) {
			if (prices[i] > prices[i-1]) {
				profit += prices[i] - prices[i-1];
			}
        }
        
        return profit;
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
