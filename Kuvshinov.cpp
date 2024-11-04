#include <vector>
#include "Kuvshinov.h"

std::vector<int> findDivisors(int n) {
    std::vector<int> divisors;

    if (n <= 0) {
        return divisors; // Возвращаем пустой вектор для некорректного ввода
    }

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) { // Избегаем добавления квадрата корня дважды
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}
