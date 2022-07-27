#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lenA = A.length();
        int lenB = B.length();
        string C;
        int times = lenB / lenA;
        if (lenB % lenA != 0) ++times;
        for (int i = 0; i < times; ++i) {
            C += A;
        }
        if (C.find(B) != std::string::npos) {
            return times;
        } else {
            C += A;
            if (C.find(B) != std::string::npos) {
                return times + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    string a;
    string b;

    cin >> a;
    cin >> b;
    Solution solution;
    cout << solution.repeatedStringMatch(a, b) << endl;

    return 0;
}
