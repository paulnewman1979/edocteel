#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool YLessComp(vector<int>& a, vector<int>& b) {
    return (a[1] < b[1]);
}
bool YLargerComp(vector<int>& a, vector<int>& b) {
    return (a[1] > b[1]);
}
bool XLargerComp(vector<int>& a, vector<int>& b) {
    return (a[0] > b[0]);
}
bool XLessComp(vector<int>& a, vector<int>& b) {
    return (a[0] < b[0]);
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() <= 2) return points;
        int i, size = points.size();
        int num1, denom1, num2, denom2;
        bool oneLine = true;
        num1 = points[1][1] - points[0][1];
        denom1 = points[1][0] - points[0][0];
        for (i = 2; i < points.size(); ++i) {
            num2 = points[i][1] - points[0][1];
            denom2 = points[i][0] - points[0][0];
            if (num1 * denom2 != num2 * denom1) {
                oneLine = false;
                break;
            }
        }
        if (oneLine) return points;

        vector<vector<int>> results;
        vector<vector<int>> todo;
        int xMin = 100, xMax = 0, yMin = 100, yMax = 0;
        for (i = 0; i < size; ++i) {
            if (xMin > points[i][0]) xMin = points[i][0];
            if (xMax < points[i][0]) xMax = points[i][0];
            if (yMin > points[i][1]) yMin = points[i][1];
            if (yMax < points[i][1]) yMax = points[i][1];
        }

        for (i = 0; i < size; ++i) {
            if (points[i][0] == xMin) {
                results.push_back(vector({points[i][0], points[i][1]}));
            }
        }
        sort(results.begin(), results.end(), YLessComp);
        vector<int> cur  = results.back();
        while (cur[1] != yMax) {
            todo.clear();
            num1 = 0;
            denom1 = 1;
            for (i = 0; i < size; ++i) {
                if (points[i][0] > cur[0]) {
                    num2 = points[i][1] - cur[1];
                    denom2 = points[i][0] - cur[0];
                    if (num2 * denom1 > num1 * denom2) {
                        num1 = num2;
                        denom1 = denom2;
                        todo.clear(); todo.push_back(vector({points[i][0], points[i][1]}));
                    } else if (num2 * denom1 == num1 * denom2) {
                        todo.push_back(vector({points[i][0], points[i][1]}));
                    }
                }
            }
            sort(todo.begin(), todo.end(), YLessComp);
            results.insert(results.end(), todo.begin(), todo.end());
            cur = results.back();
        }

        todo.clear();
        for (i = 0; i < size; ++i) {
            if ((points[i][1] == yMax) && (points[i][0] != cur[0])) {
                todo.push_back(vector({points[i][0], points[i][1]}));
            }
        }
        sort(todo.begin(), todo.end(), XLessComp);
        results.insert(results.end(), todo.begin(), todo.end());
        cur = results.back();

        while (cur[0] != xMax) {
            todo.clear();
            num1 = -100;
            denom1 = 1;
            for (i = 0; i < size; ++i) {
                if (points[i][0] > cur[0]) {
                    num2 = points[i][1] - cur[1];
                    denom2 = points[i][0] - cur[0];
                    if (num2 * denom1 > num1 * denom2) {
                        num1 = num2;
                        denom1 = denom2;
                        todo.clear();
                        todo.push_back(vector({points[i][0], points[i][1]}));
                    } else if (num2 * denom1 == num1 * denom2) {
                        todo.push_back(vector({points[i][0], points[i][1]}));
                    }
                }
            }
            sort(todo.begin(), todo.end(), YLargerComp);
            results.insert(results.end(), todo.begin(), todo.end());
            cur = results.back();
        }

        todo.clear();
        for (i = 0; i < size; ++i) {
            if ((points[i][0] == xMax) && (points[i][1] != cur[1])) {
                todo.push_back(vector({points[i][0], points[i][1]}));
            }
        }
        sort(todo.begin(), todo.end(), YLargerComp);
        results.insert(results.end(), todo.begin(), todo.end());
        cur = results.back();

        while (cur[1] != yMin) {
            todo.clear();
            num1 = 0;
            denom1 = 1;
            for (i = 0; i < size; ++i) {
                if (points[i][1] < cur[1]) {
                    num2 = cur[1] - points[i][1];
                    denom2 = cur[0] - points[i][0];
                    if (num2 * denom1 > num1 * denom2) {
                        num1 = num2;
                        denom1 = denom2;
                        todo.clear(); todo.push_back(vector({points[i][0], points[i][1]}));
                    } else if (num2 * denom1 == num1 * denom2) {
                        todo.push_back(vector({points[i][0], points[i][1]}));
                    }
                }
            }
            sort(todo.begin(), todo.end(), YLargerComp);
            results.insert(results.end(), todo.begin(), todo.end());
            cur = results.back();
        }

        todo.clear();
        for (i = 0; i < size; ++i) {
            if ((points[i][1] == yMin) && (points[i][0] != cur[0])) {
                todo.push_back(vector({points[i][0], points[i][1]}));
            }
        }
        sort(todo.begin(), todo.end(), XLargerComp);
        results.insert(results.end(), todo.begin(), todo.end());
        cur = results.back();

        while (cur[0] != xMin) {
            todo.clear();
            num1 = -100;
            denom1 = 1;
            for (i = 0; i < size; ++i) {
                if (points[i][0] < cur[0]) {
                    num2 = cur[1] - points[i][1];
                    denom2 = cur[0] - points[i][0];
                    if (num2 * denom1 > num1 * denom2) {
                        num1 = num2;
                        denom1 = denom2;
                        todo.clear(); todo.push_back(vector({points[i][0], points[i][1]}));
                    } else if (num2 * denom1 == num1 * denom2) {
                        todo.push_back(vector({points[i][0], points[i][1]}));
                    }
                }
            }
            sort(todo.begin(), todo.end(), YLessComp);
            results.insert(results.end(), todo.begin(), todo.end());
            cur = results.back();
        }
        results.pop_back();

        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
	vector< vector<int> > valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
	vector<vector<int> > results = solution.outerTrees(valueGrid);

    // output
    Output(results);

    return 0;
}
