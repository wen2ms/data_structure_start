#include <cstdint>
#include <iostream>

int64_t fast_pow(int64_t base, int64_t exp, int64_t mod) {
    int64_t result = 1;
    base %= mod;
    while (exp > 0) {
        if ((exp & 1) == 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// mod is a prime, num is not zero
int64_t mod_inv(int64_t num, int64_t mod) {
    return fast_pow(num, mod - 2, mod);
}

int main() {
    const int kMod = 5;
    std::cout << mod_inv(7, kMod) << '\n';

    return 0;
}