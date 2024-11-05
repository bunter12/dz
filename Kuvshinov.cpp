#include "Kuvshinov.h"
#include <cmath>

bool Kuvshinov(int n) {
    if (n <= 1) return false; 


    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return false; 
        }
    }

    return true; 
}
