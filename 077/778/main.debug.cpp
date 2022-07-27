#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool comp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
    return (a.first > b.first);
}

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size() - 1;
        int ret = 0, x, y;
        vector<pair<int, pair<int, int>>> edges;
        vector<vector<int>> mark(N + 1, vector<int>(N + 1, 0));
        edges.push_back(make_pair(grid[0][0], make_pair(0, 0)));
        make_heap(edges.begin(), edges.end(), comp);
        mark[0][0] = 1;
        cout << "mark\t" << (0) << "\t" << (0) << "\t1\t" << grid[0][0] << endl;
        while (mark[N][N] != 2) {
            ret = edges.front().first;
            x = edges.front().second.first;
            y = edges.front().second.second;
            pop_heap(edges.begin(), edges.end(), comp);
            edges.pop_back();
            cout << "after pop min heap\t" << edges.front().first << endl;

            vector<pair<int, int>> todo;
            vector<pair<int, int>> tmp;
            todo.push_back(make_pair(x, y));
            mark[x][y] = 2;
            cout << "*** ret " << ret << endl;
            cout << "mark\t" << (x) << "\t" << (y) << "\t2\t" << grid[x][y] << endl;
            while (todo.size() > 0) {
                tmp.clear();
                for (auto p : todo) {
                    x = p.first; y = p.second;
                    if ((x > 0) && (mark[x-1][y]==0)) {
                        if (grid[x-1][y]<ret) {
                            tmp.push_back(make_pair(x-1,y));
                            mark[x-1][y] = 2;
                            cout << "mark\t" << (x-1) << "\t" << (y) << "\t2\t" << grid[x-1][y] << endl;
                        } else {
                            mark[x-1][y] = 1;
                            cout << "mark\t" << (x-1) << "\t" << (y) << "\t2\t" << grid[x-1][y] << endl;
                            edges.push_back(make_pair(grid[x-1][y], make_pair(x-1, y)));
                            push_heap(edges.begin(), edges.end(), comp);
                            cout << "min heap\t" << edges.front().first << endl;
                        }
                    }
                    if ((y>0) && (mark[x][y-1]==0)) {
                        if (grid[x][y-1]<ret) {
                            tmp.push_back(make_pair(x,y-1));
                            mark[x][y-1] = 2;
                            cout << "mark\t" << (x) << "\t" << (y-1) << "\t1\t" << grid[x][y-1] << endl;
                        } else {
                            mark[x][y-1] = 1;
                            cout << "mark\t" << (x) << "\t" << (y-1) << "\t2\t" << grid[x][y-1] << endl;
                            edges.push_back(make_pair(grid[x][y-1], make_pair(x, y-1)));
                            push_heap(edges.begin(), edges.end(), comp);
                            cout << "min heap\t" << edges.front().first << endl;
                        }
                    }
                    if ((x<N) && (mark[x+1][y]==0)) {
                        if (grid[x+1][y]<ret) {
                            tmp.push_back(make_pair(x+1,y));
                            mark[x+1][y] = 2;
                            cout << "mark\t" << (x+1) << "\t" << (y) << "\t2\t" << grid[x+1][y] << endl;
                        } else {
                            mark[x+1][y] = 1;
                            cout << "mark\t" << (x+1) << "\t" << (y) << "\t1\t" << grid[x+1][y] << endl;
                            edges.push_back(make_pair(grid[x+1][y], make_pair(x+1, y)));
                            push_heap(edges.begin(), edges.end(), comp);
                            cout << "min heap\t" << edges.front().first << endl;
                        }
                    }
                    if ((y<N) && (mark[x][y+1]==0)) {
                        if (grid[x][y+1]<ret) {
                            cout << "mark\t" << (x) << "\t" << (y+1) << "\t2\t" << grid[x][y+1] << endl;
                            tmp.push_back(make_pair(x,y+1));
                            mark[x][y+1] = 2;
                        } else {
                            mark[x][y+1] = 1;
                            cout << "mark\t" << (x) << "\t" << (y+1) << "\t1\t" << grid[x][y+1] << endl;
                            edges.push_back(make_pair(grid[x][y+1], make_pair(x, y+1)));
                            push_heap(edges.begin(), edges.end(), comp);
                            cout << "min heap\t" << edges.front().first << endl;
                        }
                    }
                }
                todo.swap(tmp);
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.swimInWater(valueGrid);

    // output
    Output(ret);

    return 0;
}
