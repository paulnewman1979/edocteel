#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;

        if (n > 0) {
            double curX = x;
            while (n > 0) {
                if (n % 2 == 1) {
                    result *= curX;
                }
                curX = curX * curX;
                n = n / 2;
            }
        } else if (n < 0) {
            double curX = 1.0/x;
            while (n < 0) {
                if ((-n) % 2 == 1) {
                    result *= curX;
                }
                curX = curX * curX;
                n = n / 2;
            }
        }
        
        return result;
    }
};

int main(int argc, char* argv[])
{
	double x;
	int n;

    cin >> x;
	cin >> n;

    Solution solution;
	cout << solution.myPow(x, n) << endl;

    return 0;
}
