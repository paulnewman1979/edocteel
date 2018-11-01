#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int> >& dislikes) {
        int i, j, k, l;
        unordered_map<int, vector<int> > dislikeGroup;
        vector<int> setSign(N, 0);
        unordered_map<int, int> todo;
        unordered_map<int, int>::iterator iter;
        for (i = 0; i < dislikes.size(); ++i) {
            j = dislikes[i][0] - 1;
            k = dislikes[i][1] - 1;
            dislikeGroup[j].push_back(k);
            dislikeGroup[k].push_back(j);
        }

        int sign;
        for (i = 0; i < N; ++i) {
            if (setSign[i] == 0) {
                setSign[i] = 1;
                //cout << "DEBUG: 1 : " << i << " sign=" << setSign[i] << endl;
                todo[i] = 1;
                while (todo.size() > 0) {
                    iter = todo.begin();
                    j = iter->first;
                    sign = iter->second;
                    todo.erase(iter);
                    if (setSign[j] != sign) {
                        return false;
                    }
                    if (dislikeGroup.find(j) != dislikeGroup.end()) {
                        for (k = 0; k < dislikeGroup[j].size(); ++k) {
                            l = dislikeGroup[j][k];
                            switch(setSign[l]) {
                            case 0:
                                setSign[l] = 3 - sign;
                                //cout << "DEBUG: 2 : " << l << " sign=" << setSign[l] << endl;
                                todo[l] = 3 - sign;
                                break;
                            default:
                                if (setSign[l] == sign) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    int N;
    vector< vector<int> > lines;

    int n;
    int n1;
    int value;
    vector<int> line;

    cin >> N;
    cin >> n;
    while (n > 0) {
        cin >> n1;
        line.clear();
        while (n1 > 0) {
            cin >> value;
            line.push_back(value);
            --n1;
        }
        lines.push_back(line);
        --n;
    }

    Solution solution;
    cout << (solution.possibleBipartition(N, lines) ? "true" : "false") << endl;

    return 0;
}
