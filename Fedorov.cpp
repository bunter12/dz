#include <iostream>
#include <vector>
#include "Fedorov.h"

std::vector<int> sieveOfAtkin(int n) {
    std::vector<bool> isPrime(n + 1, false);
    std::vector<int> primes={2,3};

    int sqrtn = sqrt(n);

    for (int x = 1; x <= sqrtn; x++) {
        for (int y = 1; y <= sqrtn; y++) {
            int p = (4 * x * x) + (y * y);
            if (p <= n && (p % 12 == 1 || p % 12 == 5)) {
                isPrime[p] = !isPrime[p];
            }

            p = (3 * x * x) + (y * y);
            if (p <= n && p % 12 == 7) {
                isPrime[p] = !isPrime[p];
            }

            p = (3 * x * x) - (y * y);
            if (x > y && p <= n && p % 12 == 11) {
                isPrime[p] = !isPrime[p];
            }
        }
    }

    for (int p = 5; p <= sqrtn; p++) {
        if (isPrime[p]) {
            int x = p * p;
            for (int k = x; k <= n; k += x) {
                isPrime[k] = false;
            }
        }
    }

    for (int p = 5; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}