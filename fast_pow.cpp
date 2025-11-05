#include <cstdint>
#include <iostream>

int64_t fast_pow(int64_t base, int64_t exp) {
    int64_t result = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

int main() {
    std::cout << fast_pow(3, 3) << '\n';

    return 0;
}