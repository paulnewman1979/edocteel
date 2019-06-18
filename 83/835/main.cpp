#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        masks.resize(31, 0);
        int size = A.size();
        masks[0] = 0;
        for (int i = 1; i <= size; ++i) {
            masks[i] = (masks[i - 1]<<1) + 1;
        }
        vector<unsigned int> numA(size, 0), numB(size, 0);
        composeNum(A, B, numA, numB);

        unsigned int maxMatch = 0;
        moveOverlap(numA, numB, maxMatch);
        moveOverlap(numB, numA, maxMatch);
        return maxMatch;
    }

private:
    void composeNum(vector<vector<int>>& A,
            vector<vector<int>>& B,
            vector<unsigned int>& numA,
            vector<unsigned int>& numB) {
        int size = A.size();
        int i, j;
        for (i = 0; i < size; ++i) {
            for (j = size - 1; j >= 0; --j) {
                numA[i] |= (A[i][j]<<(size - 1 - j));
                numB[i] |= (B[i][j]<<(size - 1 - j));
            }
        }
    }

    void moveOverlap(vector<unsigned int>& numA,
            vector<unsigned int>& numB,
            unsigned int& maxMatch) {
        int size = numA.size();
        int i, j, k, match;
        // move B i down
        for (i = 0; i < size; ++i) {
            match = 0;
            // move B j left
            for (j = 0; j < size; ++j) {
                match = 0;
                for (k = 0; i + k < size; ++k) {
                    match += countDigits(numA[i + k] & (numB[k]<<j) & masks[size]);
                    //cout << "match=" << match << ", k=" << k << endl;
                }
                //cout << "i=" << i << ", j=" << j << ", match=" << match << endl;
                if (match > maxMatch) {
                    maxMatch = match;
                }
            }

            // move B j right
            for (j = 1; j < size; ++j) {
                match = 0;
                for (k = 0; k + i < size; ++k) {
                    match += countDigits(numA[i] & (numB[k]>>j));
                }
                if (match > maxMatch) {
                    maxMatch = match;
                }
            }
        }
    }

    int countDigits(int a) {
        int i = a;
        i = ((i&0xaaaaaaaa)>>1)  + (i&0x55555555);
        i = ((i&0xcccccccc)>>2)  + (i&0x33333333);
        i = ((i&0xf0f0f0f0)>>4)  + (i&0x0f0f0f0f);
        i = ((i&0xff00ff00)>>8)  + (i&0x00ff00ff);
        i = ((i&0xffff0000)>>16) + (i&0x0000ffff);
        //cout << "a=" << a << ", i=" << i << endl;
        return i;
    }

    vector<int> masks;
};

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > valueGrid;
    vector< vector<int> > valueGrid1;

    // variable
    int n;
    int nn;
    vector<int> valueLine;
    int value;

    // input
    cin >> n;
    while (n-- > 0) {
        cin >> nn;
        valueLine.clear();
        while (nn-- > 0) {
            cin >> value;
            valueLine.push_back(value);
        }
        valueGrid.push_back(valueLine);
    }

    cin >> n;
    while (n-- > 0) {
        cin >> nn;
        valueLine.clear();
        while (nn-- > 0) {
            cin >> value;
            valueLine.push_back(value);
        }
        valueGrid1.push_back(valueLine);
    }


    Solution solution;
    cout << solution.largestOverlap(valueGrid, valueGrid1) << endl;

    return 0;
}
