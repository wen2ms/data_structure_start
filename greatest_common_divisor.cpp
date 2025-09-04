#include <iostream>
#include <vector>

// int gcd(int a, int b) {
//     while (b != 0) {
//         int tmp = a;

//         a = b;

//         b = tmp % b;
//     }

//     return a;
// }

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcd(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    std::cout << gcd(3, 12) << ' ' << lcd(3, 12) << '\n';

    std::cout << gcd(7, 9) << ' ' << lcd(7, 9) << '\n';

    return 0;
}