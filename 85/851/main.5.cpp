#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int i, j, size = quiet.size();

        // initial 
        vector<int> result(size);
        vector<int> richersCount(size);
        vector<vector<int> > poorers(size);
        for (i = 0; i < richer.size(); ++i) {
            richersCount[richer[i][1]]++;
            poorers[richer[i][0]].push_back(richer[i][1]);
        }
        vector<int> todo;
        for (i = 0; i < size; ++i) {
            result[i] = i;
            if (richersCount[i] == 0) {
                result[i] = i;
                todo.push_back(i);
            }
        }
        vector<int>::iterator iter;
        while (todo.size() > 0) {
            i = todo.back();
            todo.pop_back();
            for (iter = poorers[i].begin(); iter != poorers[i].end(); ++iter) {
                j = *iter;
                if (quiet[result[i]] < quiet[result[j]]) {
                    result[j] = result[i];
                }
                richersCount[j]--;
                if (richersCount[j] == 0) {
                    todo.push_back(j);
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
	int n;
    int n1;
    int value;

    vector<int> quiet;
	vector< vector<int> > edges;
	vector<int> edge;

    cin >> n;
    while (n > 0) {
        cin >> value;
        quiet.push_back(value);
        --n;
    }

	cin >> n;
	while (n > 0) {
        cin >> n1;
        edge.clear();
        while (n1 > 0) {
            cin >> value;
            edge.push_back(value);
            --n1;
        }
	    edges.push_back(edge);
        --n;
	}

    Solution solution;
	edge = solution.loudAndRich(edges, quiet);
    for (int i = 0; i < edge.size(); ++i) {
        cout << edge[i] << endl;
    }
    cout << endl;

    return 0;
}
