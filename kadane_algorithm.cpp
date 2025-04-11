#include <iostream>
#include <vector>
#include <climits>

int kadane(const std::vector<int> integers) {
    int maximum = INT_MIN;
    int current_sum = 0;

    for (int i = 0; i < integers.size(); ++i) {
        current_sum = std::max(current_sum + integers[i], integers[i]);
        maximum = std::max(current_sum, maximum);
    }
    return maximum;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> input_integers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input_integers[i];
    }

    std::cout << kadane(input_integers) << std::endl;

    return 0;
}