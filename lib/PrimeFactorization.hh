#ifndef __TAOLIU_PRIME_FACTORIZATION_HH__
#define __TAOLIU_PRIME_FACTORIZATION_HH__

#include <iostream>
#include <vector>
#include <string>

class PrimeFactorization {
public:
    PrimeFactorization() {}
    ~PrimeFactorization() {}
    
    void run(int N, std::vector<int>& factors);
};

#endif // __TAOLIU_PRIME_FACTORIZATION_HH__
