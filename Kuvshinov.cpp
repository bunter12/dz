// Kuvshinov.cpp
#include "Kuvshinov.h"
#include <cmath> // для функции sqrt

bool isPrime(int n) {
    if (n <= 1) return false;         // Числа меньше 2 не являются простыми
    if (n <= 3) return true;          // 2 и 3 — простые числа
    if (n % 2 == 0 || n % 3 == 0) return false; // Исключаем четные и кратные 3

    // Проверка делителей от 5 до sqrt(n) с шагом 6 (5, 7, 11, 13, ...)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true; // Если делители не найдены, число простое
}
