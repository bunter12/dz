#include "Kuvshinov.h"
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false; // Числа меньше или равные 1 не являются простыми

    // Перебор всех чисел от 2 до sqrt(n)
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return false; // Если найден делитель, число не простое
        }
    }

    return true; // Если делителей не найдено, число простое
}
