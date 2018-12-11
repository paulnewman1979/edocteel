#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        int i, j;
        i = people.size() - 1;
        j = 0;
        while (i > j) {
            if (people[i] + people[j] <= limit) {
                ++j;
            }
            --i;
            ++count;
        }
        if (i == j) ++count;
        return count;
    }
};

int main(int argc, char* argv[])
{
    int limit;
    int n;
    vector<int> values;
    int value;

    cin >> limit;
    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }

    Solution solution;
    cout << solution.numRescueBoats(values, limit) << endl;

    return 0;
}
