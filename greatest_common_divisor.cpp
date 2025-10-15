#include <iostream>
#include <numeric>

// int gcd(int a, int b) {
//     while (b != 0) {
//         int tmp = a;
//         a = b;
//         b = tmp % b;
//     }
//     return a;
// }

// std::gcd
// std::lcm

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    std::cout << gcd(3, 12) << ' ' << lcm(3, 12) << '\n';

    std::cout << gcd(7, 9) << ' ' << lcm(7, 9) << '\n';

    return 0;
}