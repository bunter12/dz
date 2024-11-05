#include <iostream>
#include <vector>
#include "Nedelko_group.h"

bool sieveOfEratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    return isPrime.back();

}
