#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score = 0;
        int value;
        vector<int> scores;
        for (int i = 0; i < ops.size(); ++i) {
            switch(ops[i][0]) {
            case 'C':
                value = 0;
                if (scores.size() > 0) {
                    value = scores.back();
                    scores.pop_back();
                }
                score -= value;
                break;
            case '+':
                value = 0;
                if (scores.size() > 1) {
                    value = scores[scores.size() - 1] + scores[scores.size()- 2];
                } else if (scores.size() > 0) {
                    value = scores[scores.size()- 1];
                }
                scores.push_back(value);
                score += value;
                break;
            case 'D':
                value = (scores.size() > 0) ? scores.back() + scores.back() : 0;
                scores.push_back(value);
                score += value;
                break;
            default:
                value = atoi(ops[i].c_str());
                scores.push_back(value);
                score += value;
            }
            //cout << score << endl;
        }
        return score;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<string> ops;
    string op;

    cin >> n;
    while (n > 0) {
        cin >> op;
        ops.push_back(op);
        --n;
    }
        
    Solution solution;
    cout << solution.calPoints(ops) << endl;

    return 0;
}
