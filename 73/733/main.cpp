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
        oldColor = image[sr][sc];
        if (oldColor == newColor) return image;

        this->newColor = newColor;
        image[sr][sc] = newColor;
        simpleFill1(image, sr, sc);
        simpleFill2(image, sr, sc);
        return image;
    }

private:
    void simpleFill1(vector<vector<int>>& image, const int sr, const int sc) {
        for (int i = sr - 1; i >= 0; --i) {
            if (image[i][sc] == oldColor) {
                image[i][sc] = newColor;
                simpleFill2(image, i, sc);
            } else break;
        }
        for (int i = sr + 1; i < image.size(); ++i) {
            if (image[i][sc] == oldColor) {
                image[i][sc] = newColor;
                simpleFill2(image, i, sc);
            } else break;
        }
    }

    void simpleFill2(vector<vector<int>>& image, const int sr, const int sc) {
        for (int i = sc - 1; i >= 0; --i) {
            if (image[sr][i] == oldColor) {
                image[sr][i] = newColor;
                simpleFill1(image, sr, i);
            } else break;
        }
        for (int i = sc + 1; i < image[0].size(); ++i) {
            if (image[sr][i] == oldColor) {
                image[sr][i] = newColor;
                simpleFill1(image, sr, i);
            } else break;
        }
    }

private:
    int newColor;
    int oldColor;
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
