#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "PrimeFactorization.hh"

using namespace std;

void PrimeFactorization::run(int N, vector<int>& factors)
{
    int n = N;
    while ((n & 1) == 0) {
        factors.push_back(2);
        n = n>>1;
    }

    int sqrtN = sqrt(n);
    int factor = 3;
    while (n != 1) {
        if (n % factor == 0) {
            while (n % factor == 0) {
                factors.push_back(factor);
                n /= factor;
            }
            sqrtN = sqrt(n);
        }
        factor += 2;
    }
}

