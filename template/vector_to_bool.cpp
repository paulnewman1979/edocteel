#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool maxProfit(vector<int>& prices) {
        return true;
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
    cout << (solution.maxProfit(prices) ? "true" : "false") << endl;

    return 0;
}
