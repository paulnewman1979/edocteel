#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int a = p, b = q;
        while ((a != 0) && (b != 0)) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        a = a + b;
        p /= a;
        q /= a;
        if (q % 2 == 0) {
            return 0;
        } else if (p % 2 == 0) {
            return 2;
        } else {
            return 1;
        }
    }
};

int main(int argc, char* argv[])
{
	int m;
	int n;
	cin >> m;
	cin >> n;

    Solution solution;
	cout << solution.mirrorReflection(m, n) << endl;

    return 0;
}
