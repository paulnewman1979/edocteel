#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void subCombine(vector<int>& candidates,
                    vector<int>& count,
                    int target,
                    int index,
                    vector< vector<int> >& results) {
        if (0 == target) {
            vector<int> result;

            for (int i=index-1; i>=0; --i) {
                for (int j=0; j<count[i]; ++j) {
                    result.push_back(candidates[i]);
                }
            }
            results.push_back(result);
        } else if (index < candidates.size()) {
            int maxNum = target / candidates[index];
            for (int i=maxNum; i>=0; --i) {
                count[index] = i;
                subCombine(candidates, count, target - candidates[index] * i, index + 1, results);
            }

            count[index] = 0;
        }
    }

    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > results;

        std::sort(candidates.begin(), candidates.end(), greater<int>());

        vector<int> count;
        count.resize(candidates.size());
        subCombine(candidates, count, target, 0, results);

        return results;
    }
};

int main(int argc, char* argv[])
{
    int target;
    vector<int> candidates;
    int num;

    cin >> target;

    cin >> num;
    while (-1 != num) {
        candidates.push_back(num);

        cin >> num;
    }

    Solution solution;
    const vector< vector<int> > results = solution.combinationSum(candidates, target);
    cout << results.size() << endl;
    for (int i = 0; i < results.size(); ++i) {
        for (int j = 0; j<results[i].size(); ++j) {
            cout << " " << results[i][j];
        }
        cout << endl;
    }

    return 0;
}
