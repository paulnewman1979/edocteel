#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> targetPosMap;
        unordered_map<int, int>::const_iterator iter;
        vector<int> results;

        for (int i = 0; i < numbers.size(); ++i) {
            iter = targetPosMap.find(target - numbers[i]);
            if (iter != targetPosMap.end()) {
                results.push_back(iter->second + 1);
                results.push_back(i + 1);
                return results;
            } else {
                targetPosMap[numbers[i]] = i;
            }
        }

        return results;
    }
};

int main(int argc, char* argv[])
{
    int target;
    int n;
    vector<int> numbers;
    vector<int> results;
    int number;

    cin >> target;
    cin >> n;
    while (n != 0) {
        cin >> number;
        numbers.push_back(number);
        --n;
    }
        
    Solution solution;
    results = solution.twoSum(numbers, target);
    for (int i=0; i<results.size(); ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
