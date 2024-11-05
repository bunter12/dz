#include <iostream>
#include <vector>
#include "Nedelko_group.h"

std::vector<int> sieveOfEratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    std::vector<int> primeNumber;
    
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int i = 2; i<=n; i++){
        if(isPrime[i]){
            primeNumber.push_back(i);
        }
    }
    return primeNumber;
}
