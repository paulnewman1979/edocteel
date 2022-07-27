#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int maxDistance = 0;
        int lastPos = -1;
        int curPos = 0;
        while (N > 0) {
            if (N % 2 == 1) {
                if ((lastPos >= 0) &&
                        (curPos - lastPos > maxDistance)) {
                    maxDistance = curPos - lastPos;
                }
                lastPos = curPos;
            }
            N = N>>1;
            ++curPos;
        }
        
        return maxDistance;
    }
};

int main(int argc, char* argv[])
{
    int N;
    cin >> N;

    Solution solution;
    cout << solution.binaryGap(N) << endl;

    return 0;
}
