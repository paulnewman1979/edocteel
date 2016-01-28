#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void coinChange(const vector<int>& coins, const int amount, const int index, const int cur_size, int& min_size) {
        if (amount == 0) {
            if (cur_size < min_size) {
                min_size = cur_size;
            }
            return;
        }
        if (amount % coins[index] == 0) {
            if (cur_size + amount/coins[index] < min_size) {
                min_size = cur_size + amount / coins[index];
            }
            return;
        } else if (index == coins.size() - 1) {
            return;
        }

        int index_max = amount / coins[index];
        int index_size = 0;
        for (index_size=index_max; index_size>=0; index_size--) {
            coinChange(coins, amount - index_size * coins[index], index + 1, cur_size + index_size, min_size);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        if (0 == coins.size()) {
            return -1;
        }
        sort(coins.begin(), coins.end(), greater<int>());

        int min_size = amount + 1;
        int cur_size = 0;
        coinChange(coins, amount, 0, cur_size, min_size);
        if (min_size == amount + 1) {
            min_size = -1;
        }
        return min_size;
    }
};

int main(int argc, char* argv[])
{
    vector<int> coins;
    int amount;
    cin >> amount;
    int num;
    cin >> num;
    while (num != -999999)
    {
        coins.push_back(num);
        cin >> num;
    }

    Solution solution;
    num = solution.coinChange(coins, amount);
    cout << num << endl;
}
