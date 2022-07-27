#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<pair<int, int>> todo;
        vector<pair<int, int>> tmp;
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        image[sr][sc] = newColor;
        todo.push_back(make_pair(sr, sc));
        while (todo.size() > 0) {
            tmp.clear();
            for (auto p : todo) {
                int x = p.first, y = p.second;
                if ((x > 0) && (image[x - 1][y] == oldColor)) {
                    tmp.push_back(make_pair(x - 1, y));
                    image[x-1][y] = newColor;
                }
                if ((y > 0) && (image[x][y - 1] == oldColor)) {
                    tmp.push_back(make_pair(x, y - 1));
                    image[x][y-1] = newColor;
                }
                if ((x + 1 < image.size()) && (image[x + 1][y] == oldColor)) {
                    tmp.push_back(make_pair(x + 1, y));
                    image[x + 1][y] = newColor;
                }
                if ((y + 1 < image[0].size()) && (image[x][y + 1] == oldColor)) {
                    tmp.push_back(make_pair(x, y + 1));
                    image[x][y + 1] = newColor;
                }
            }
            todo.swap(tmp);
        }
        return image;
    }
};

int main(int argc, char* argv[])
{
    // input
    int sr, sc, newColor;
	vector< vector<int> > edges;
    Input(sr);
    Input(sc);
    Input(newColor);
    Input(edges);

    // solution
    Solution solution;
	vector<vector<int> > ret = solution.floodFill(edges, sr, sc, newColor);

    // output
    Output(ret );

    return 0;
}
