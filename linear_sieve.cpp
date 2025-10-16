#include <iostream>
#include <vector>

std::vector<int> linear_sieve(int n) {
    std::vector<int> primes;
    std::vector<bool> is_prime(n + 1, true);
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int prime : primes) {
            if (i * prime > n) {
                break;
            }
            is_prime[i * prime] = false;
            if (i % prime == 0) {
                break;
            }
        }
    }
    return primes;
}

int main() {
    std::vector<int> primes = linear_sieve(20);
    for (int prime : primes) {
        std::cout << prime << ' ';
    }
    std::cout << '\n';

    return 0;
}