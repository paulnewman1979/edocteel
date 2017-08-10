#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
