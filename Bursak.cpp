#include <iostream>
#include <vector>
#include "Bursak.h"
using namespace std;

vector<int> Sundaram(int N) {
    int newN = (N - 1) / 2;
    vector<bool> prime_numbers(newN + 1, true);
    
    // Алгоритм Сундарама для нахождения простых чисел
    for (long long i = 1; i <= newN; ++i) {
        for (long long j = i; (i + j + 2 * i * j) <= newN; ++j) {
            prime_numbers[i + j + 2 * i * j] = false;
        }
    }

    // Сбор простых чисел в вектор
    vector<int> primes;
    if (N > 2) {
        primes.push_back(2); // Число 2 — единственное чётное простое
    }

    for (int i = 1; i <= newN; ++i) {
        if (prime_numbers[i]) {
            primes.push_back(2 * i + 1);
        }
    }

    return primes;
}
