#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "PrimeFactorization.hh"

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);

    PrimeFactorization pf;
    std::vector<int> factors;
    pf.run(N, factors);
    for (int i = 0; i < factors.size(); ++i) {
        std::cout << factors[i] << (((i % 8) == 7) ? "\t" : "\n");
    }

    return 0;
}

