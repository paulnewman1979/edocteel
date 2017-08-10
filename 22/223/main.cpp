#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // A C  E G
        // B D  F H
        if ((A >= G) || (C <= E) || (B >= H) || (D <= F)) {
            return (C - A) * (D - B) + (G - E) * (H - F);
        } else {
            int area = (C - A) * (D - B) + (G - E) * (H - F);
            int s1 = (A <= E) ? E : A;
            int s2 = (C <= G) ? C : G;
            int s3 = (B <= F) ? F : B;
            int s4 = (D <= H) ? D : H;
            return area - (s2 - s1) * (s4 - s3);
        }
    }
};

int main(int argc, char* argv[])
{
    int A, B, C, D, E, F, G, H;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    cin >> E;
    cin >> F;
    cin >> G;
    cin >> H;

    Solution solution;
    cout << solution.computeArea(A, B, C, D, E, F, G, H) << endl;

    return 0;
}
