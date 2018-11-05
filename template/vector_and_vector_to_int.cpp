#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    //int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
    int profitableSchemes(vector<int>& group, vector<int>& profit) {
        return 0;
    }
};

int main(int argc, char* argv[])
{
    vector<int> group;
    vector<int> profit;
    int value;

    int n;
    cin >> n;
    while (n > 0) {
        cin >> value;
        group.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        profit.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.profitableSchemes(group, profit) << endl;

    return 0;
}
