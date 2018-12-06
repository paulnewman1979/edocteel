#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        unsigned long long result = 0;
        unsigned long long rA = A;
        unsigned long long rB = B;

        // commonDivisor & commonMultiple
        unsigned long long commonDivisor = 0;
        while ((rA != 0) && (rB != 0)) {
            if (rA > rB) rA = rA % rB;
            else rB = rB % rA;
        }
        commonDivisor = (rA == 0) ? rB : rA;
        rA = A / commonDivisor;
        rB = B / commonDivisor;
        unsigned long long commonMultiple = rA * rB * commonDivisor;

        // check how many
        int rN = N / (rA + rB - 1);
        result = rN * commonMultiple % modulo;

        rN = N % (rA + rB - 1);
        if (rN > 0) {
            unsigned long long timesA = (rN * commonDivisor * rA * rB - 1)/ (rA + rB) + 1;
            unsigned long long timesB = timesA;
            //cout << rA << endl;
            //cout << rB << endl;
            //cout << rN << endl;
            //cout << commonDivisor << endl;
            //cout << commonMultiple << endl;
            //cout << timesA << endl;
            //cout << timesB << endl;
            timesA = (timesA + A - 1) / A * A;
            timesB = (timesB + B - 1) / B * B;
            result += (timesA < timesB) ? timesA : timesB;
            result = result % modulo;
        }

        return result;
    }

private:
    static const unsigned long long modulo = 1000000007;
};

int main(int argc, char* argv[])
{
    int N;
    int A;
    int B;

	cin >> N;
	cin >> A;
	cin >> B;

    Solution solution;
	cout << solution.nthMagicalNumber(N, A, B) << endl;

    return 0;
}
